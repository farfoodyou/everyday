#include <iostream>

template <class T>
void printValue(T& o){
    std::cout << o.Value() << std::endl;
}

class Base {
protected:
    int value;
public:
    int Value(){
        std::cout << " Base class Value " << std::endl;
        return value;
    }
    int SetValue(int v){
        value = v;
        return 0;
    }
    virtual void print(){
        std::cout << " base class" << std::endl;
    }
};

class A :public Base {
public:
    A(){
        value = 2;
    }
    int Value(){
        std::cout << " A class Balue " << std::endl;
        return value/2;
    }
    int Value2(){
        return value * 2;
    }
    virtual void print(){
        std::cout << " A class " << std::endl;
    }
};
class B:public Base {
public:
    virtual void print(){
        std::cout << " B class " << std::endl;
    }
};

int main(){
    Base o;
    printValue(o);
    o.SetValue(1234);
    printValue(o);
    A a;
    printValue(a);
    Base &ao = a;
    a.print();
    ao.print();
    // 下面的结果不同
    printValue(ao);
    printValue(a);

    B b;
    printValue(b);
    Base &bo = b;
    b.print();
    bo.print();
    return 0;
}

/*
用模板的时候, 如果重载了, 子类用的是子类的函数, 基类用的是基类的函数. 
如果用的是虚函数, 那就能够调用子类的函数.
*/