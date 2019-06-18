#include "rapidjson/document.h"     // rapidjson's DOM-style API
#include "rapidjson/prettywriter.h" // for stringify JSON
#include <cstdio>
#include <string>
#include <iostream>

using namespace rapidjson;
using namespace std;

class mybase {
public:
    int id;
    int hi(){
        return this->id;
    };
    mybase(){
        id = 123;
    };
};
void diff_json(const Document& a,const Document& b);

int main(){

    std::string json1("{\"hello\":\"world\",\"t\":true,\"f\":false,\"n\":null,\"i\":123,\"pi\":3.1416,\"a\":[1,2,3,4]}");
    Document doc1;

    if (doc1.Parse(json1.c_str()).HasParseError())
        return 1;

    assert(doc1.HasMember("hello"));
    assert(doc1["hello"].IsString());
    printf("hello 1= %s\n", doc1["hello"].GetString());
    //printf("z 1  = %s\n", doc1["z"]["x"].GetString());

    std::string json("{\"hello\":\"wo3333rld\",\"t\":true,\"f\":false,\"n\":null,\"i\":123,\"pi\":3.1416,\"a\":[1,2,3,4],\"z\":{\"x\":\"xx\"}}");
    Document doc;

    if (doc.Parse(json.c_str()).HasParseError())
        return 1;

    assert(doc.HasMember("hello"));
    assert(doc["hello"].IsString());
    printf("hello = %s\n", doc["hello"].GetString());
    printf("z = %s\n", doc["z"]["x"].GetString());

    std::string json2("[\"xx\",\"eee\"]");
    Document doc2;

    if (doc2.Parse(json2.c_str()).HasParseError() || !doc2.IsArray()){
        printf("json2 err");
        return 1;
    }
    printf("doc2 1= %s\n", doc2[1].GetString());

    // 开始 json 递归检查是否相同
    std::string diff_json_1("{\"hello\":\"wo3333rld\",\"t\":true,\"f\":false,\"n\":null,\"i\":123,\"a\":[1,2,3,{\"s\":33}],\"z\":{\"x\":\"xx\"},\"pi\":3.1416}");
    std::string diff_json_2("{\"hello\":\"wo3333rld\",\"t\":true,\"f\":false,\"n\":null,\"i\":123,\"pi\":3.1416,\"a\":[1,2,3,{\"s\":33}],\"z\":{\"x\":\"xx\"}}");
    Document diff_doc_1;
    Document diff_doc_2;
    diff_doc_1.Parse(diff_json_1.c_str());
    diff_doc_2.Parse(diff_json_2.c_str());
    if(diff_doc_1 == diff_doc_2) {
        cout << " same json " << endl;
    } else {
        cout << " diff " << endl;
    }
    diff_json(diff_doc_1, diff_doc_2);

    return 0;
}

static const char* kTypeNames[] = 
    { "Null", "False", "True", "Object", "Array", "String", "Number" };
void diff_json(const Document& base_document, const Document& diff_document) {
    if (base_document.MemberCount() != diff_document.MemberCount()) {
        cout << " diff size " << endl;
    }
    for (Value::ConstMemberIterator itr = base_document.MemberBegin(),
        diff_itr = diff_document.MemberBegin();
        itr != base_document.MemberEnd() && diff_itr != diff_document.MemberEnd(); 
        ++itr, ++diff_itr)
    {
        printf("Type of member %s is %s\n",
            itr->name.GetString(), kTypeNames[itr->value.GetType()]);
        printf("Type of member %s is %s\n",
            diff_itr->name.GetString(), kTypeNames[diff_itr->value.GetType()]);
    }
}

// 通用 json diff 工具
