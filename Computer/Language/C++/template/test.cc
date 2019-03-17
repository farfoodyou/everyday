#include <iostream>

template <class T>
void printValue(T& o){
    std::cout << o.Value() << std::endl;
}

class Base {
    int value;
public:
    int Value(){
        return value;
    }
    int SetValue(int v){
        value = v;
        return 0;
    }
};

int main(){
    Base o;
    printValue(o);
    o.SetValue(1234);
    printValue(o);
    return 0;
}