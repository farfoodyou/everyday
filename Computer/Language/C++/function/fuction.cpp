#include <cstdio>
#include <iostream>

class A{
public:
    void hi(){
        std::cout << "A hi" <<std::endl;
    }
};

class B :public A{
public:
    void hi(){
        std::cout << "B hi" <<std::endl;
        A::hi();
    }
};

class C :public B{
public:
    void hi(){
        std::cout << "C hi" <<std::endl;
        B::hi();
    }
};

int main(){
    A a;
    a.hi();
    B* b;
    b = (B*)&a;
    b->hi();
    C c;
    c.hi();

    printf("a %p\n",&A::hi);
    printf("b %p\n",&B::hi);
    return 0;
}