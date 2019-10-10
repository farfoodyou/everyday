#include <cstdio>
#include <memory>
#include <iostream>

class parent {
public:
    int name;
    virtual ~parent(){std::cout << "~base" << std::endl;}
};

class child1 :public parent {
public:
    int nick_name;
    child1():nick_name("child1") {}
};

class child2 :public parent {
public:
    int nick_name;
    child2():nick_name("child2") {}
};

class child3 :public parent {
public:
    int nick_name;
    child3():nick_name("child3") {}
};

int main(){
    std::shared_ptr<parent> pptr = std::make_shared<child>();


    std::cout << pptr->name << std::endl;

    auto nick_ptr = std::dynamic_pointer_cast<child>(pptr);

    std::cout << nick_ptr->nick_name << std::endl;

}
