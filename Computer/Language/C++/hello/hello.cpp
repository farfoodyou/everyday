#include <cstdio>
#include <iostream>

enum Color {
    red, blue, yellow, green
};

void print(Color c){
    switch(c){
        case red:
            std::cout << "red" << std::endl;
            break;
        default:
            std::cout << "not red" << std::endl;
    }
}

int main(){
    Color c = red;
    print(c);
    c = blue;
    print(c);
    return 0;
}