#include <cstdio>
#include <cstdlib>
#include <string>
#include <map>
#include <vector>

// clang++ -g -O3 word.cpp

enum Token{
    tok_eof = -1,
    tok_def = -2, tok_extern = -3,
    tok_identifier = -4, tok_number = -5
};

static std::string IdentifierStr;
static double NumVal;

static int gettok(){
    static int LastChar = ' ';
    while(isspace(LastChar))
        LastChar = getchar();

    if(isalpha(LastChar)){
        IdentifierStr = LastChar;
        while(isalnum((LastChar = getchar())))
            IdentifierStr += LastChar;

        if(IdentifierStr == "def")return tok_def;
        if(IdentifierStr == "extern")return tok_extern;
        return tok_identifier;
    }

    if(isdigit(LastChar) || LastChar == '.'){
        std::string NumStr;
        do{
            NumStr += LastChar;
            LastChar = getchar();
        }while(isdigit(LastChar) || LastChar == '.');

        NumVal = strtod(NumStr.c_str(), 0);
        return tok_number;
    }

    if(LastChar == '#'){
        do LastChar = getchar();
        while(LastChar != EOF && LastChar != '\n' && LastChar != '\r');

        if(LastChar != EOF)
            return gettok();
    }

    if(LastChar == EOF)
        return tok_eof;
    
    int ThisChar = LastChar;
    LastChar = getchar();
    return ThisChar;
}

class ExprAST{
    public:
        virtual ~ExprAST(){}
        virtual Value *Codegen() = 0;
};

class NumberExprAST :public ExprAST{
    double Val;
    public:
        NumberExprAST(double val):Val(val){}
        virtual Value *Codegen();
};

class VariableExprAST :public ExprAST{
    std::string Name;
    public:
        VariableExprAST(const std::string &name):Name(name){}
        virtual Value *Codegen();
};

class BinaryExprAST :public ExprAST{
    char Op;
    ExprAST *LHS, *RHS;
    public:
        BinaryExprAST(char op, ExprAST *lhs, ExprAST *rhs):Op(op),LHS(lhs),RHS(rhs){}
        virtual Value *Codegen();
};

class CallExprAST :public ExprAST{
    std::string Callee;
    std::vector<ExprAST*> Args;
    public:
        CallExprAST(const std::string &callee, std::vector<ExprAST*> &args):Callee(callee),Args(args){}
        virtual Value *Codegen();
};

class PrototypeAST{
    std::string Name;
    std::vector<std::string> Args;
    public:
        PrototypeAST(const std::string &name, const std::vector<std::string> &args):Name(name), Args(args){}
        virtual Value *Codegen();
};

class FunctionAST{
    PrototypeAST *Proto;
    ExprAST *Body;
    public:
        FunctionAST(PrototypeAST *proto, ExprAST *body):Proto(proto),Body(body){}
        virtual Value *Codegen();
};

static int CurTok;
static int getNextToken(){
    return CurTok = gettok();
}

ExprAST *Error(const char *Str){fprintf(stderr, "Error: %s\n", Str);return 0;}
PrototypeAST *ErrorP(const char *Str){Error(Str);return 0;}
FunctionAST *ErrorF(const char *Str){Error(Str);return 0;}
Value *ErrorV(const char *Str) { Error(Str); return 0; }

static Module *TheModule;
static IRBuilder<> Builder(getGlobalContext());
static std::map<std::string, Value*> NamedValues;
static ExprAST *ParseExpression();

static ExprAST *ParseNumberExpr(){
    ExprAST *Result = new NumberExprAST(NumVal);
    getNextToken();
    return Result;
}

static ExprAST *ParseParenExpr(){
    getNextToken();
    ExprAST *V = ParseExpression();
    if(!V)return 0;

    if(CurTok != ')')
        return Error("expected ')'");
    getNextToken();
    return V;
}

static ExprAST *ParseIdentifierExpr(){
    std::string IdName = IdentifierStr;
    getNextToken();

    if(CurTok != '(')
        return new VariableExprAST(IdName);

    getNextToken();
    std::vector<ExprAST*> Args;
    if(CurTok != ')'){
        while(1){
            ExprAST *Arg = ParseExpression();
            if(!Arg)return 0;
            Args.push_back(Arg);

            if(CurTok == ')')break;

            if(CurTok != ',')
                return Error("Expected ')' or ',' in argument list");

            getNextToken();
        }
    }

    // Eat the ')'.
    getNextToken();
    return new CallExprAST(IdName, Args);
}

static ExprAST *ParsePrimary(){
    switch(CurTok){
        default: return Error("unknown token when expecting an expression");
        case tok_identifier: return ParseIdentifierExpr();
        case tok_number:     return ParseNumberExpr();
        case '(':            return ParseParenExpr();
    }
}

static std::map<char, int> BinopPrecedence;

static int GetTokPrecedence(){
    if(!isascii(CurTok))
        return -1;
    
    int TokPrec = BinopPrecedence[CurTok];
    if(TokPrec <= 0)return -1;
    return TokPrec;
}

static ExprAST *ParseBinOpRHS(int ExprPrec, ExprAST *LHS){
    while(1){
        int TokPrec = GetTokPrecedence();

        if(TokPrec < ExprPrec)
            return LHS;

        int BinOp = CurTok;
        getNextToken();

        ExprAST *RHS = ParsePrimary();
        if(!RHS)return 0;

        int NextPrec = GetTokPrecedence();
        if(TokPrec < NextPrec){
            RHS = ParseBinOpRHS(TokPrec+1, RHS);
            if (RHS == 0) return 0;
        }

        LHS = new BinaryExprAST(BinOp, LHS, RHS);
    }
}

static ExprAST *ParseExpression(){
    ExprAST *LHS = ParsePrimary();
    if(!LHS)return 0;

    return ParseBinOpRHS(0, LHS);
}

static PrototypeAST *ParsePrototype(){
    if(CurTok != tok_identifier)
        return ErrorP("Expected function name in prototype");

    std::string FnName = IdentifierStr;
    getNextToken();

    if(CurTok != '(')
        return ErrorP("Expected '(' in prototype");

    std::vector<std::string> ArgNames;
    while(getNextToken() == tok_identifier)
        ArgNames.push_back(IdentifierStr);
    if(CurTok != ')')
        return ErrorP("Expected ')' in prototype");
    
    getNextToken();

    return new PrototypeAST(FnName, ArgNames);
}

static FunctionAST *ParseDefinition(){
    getNextToken();
    PrototypeAST *Proto = ParsePrototype();
    if(Proto == 0)return 0;

    if(ExprAST *E = ParseExpression())
        return new FunctionAST(Proto, E);
    return 0;
}

static PrototypeAST *ParseExtern(){
    getNextToken();
    return ParsePrototype();
}

static FunctionAST *ParseTopLevelExpr(){
    if(ExprAST *E = ParseExpression()){
        PrototypeAST *Proto = new PrototypeAST("", std::vector<std::string>());
        return new FunctionAST(Proto, E);
    }
    return 0;
}

//===----------------------------------------------------------------------===//
// Top-Level parsing
//===----------------------------------------------------------------------===//

static void HandleDefinition() {
  if (ParseDefinition()) {
    fprintf(stderr, "Parsed a function definition.\n");
  } else {
    // Skip token for error recovery.
    getNextToken();
  }
}

static void HandleExtern() {
  if (ParseExtern()) {
    fprintf(stderr, "Parsed an extern\n");
  } else {
    // Skip token for error recovery.
    getNextToken();
  }
}

static void HandleTopLevelExpression() {
  // Evaluate a top-level expression into an anonymous function.
  if (ParseTopLevelExpr()) {
    fprintf(stderr, "Parsed a top-level expr\n");
  } else {
    // Skip token for error recovery.
    getNextToken();
  }
}

static void MainLoop(){
    while(1){
        fprintf(stderr, "ready> ");
        switch(CurTok){
            case tok_eof: return ;
            case ';':     getNextToken();break;
            case tok_def: HandleDefinition();break;
            case tok_extern: HandleExtern();break;
            default:      HandleTopLevelExpression();break;
        }
    }
}

int main(){
    
    BinopPrecedence['<'] = 10;
    BinopPrecedence['+'] = 20;
    BinopPrecedence['-'] = 20;
    BinopPrecedence['*'] = 40;
    
    fprintf(stderr, "ready> ");
    getNextToken();

    MainLoop();

    return 0;
}
