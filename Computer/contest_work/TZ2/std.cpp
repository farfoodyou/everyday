#include <cstdio>
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

void stack(){
    std::cout << " std::stack<int> sk; " << std::endl;
    std::stack<int> sk;
    sk.push(3);
    sk.push(1);
    sk.push(5);
    sk.push(2);
    std::cout << " size :" << sk.size() << std::endl;

    std::cout << sk.top() << std::endl;
    sk.pop();

    std::cout << sk.top() << std::endl;
    sk.pop();
}

void list(){
    std::cout << " std::list<int> lt; " << std::endl;
    std::list<int> lt;
    lt.push_back(3);
    lt.push_back(1);
    lt.push_front(5);
    lt.push_back(2);

    std::cout << lt.front() << std::endl;
    std::cout << lt.back() << std::endl;

    std::cout << " 长度: " << lt.size() << std::endl;
    std::cout << " 遍历 " << std::endl;
    for( std::list<int>::iterator it = lt.begin(); it != lt.end(); it++) {
        std::cout << *it << std::endl;
    }
}

void queue(){
    std::cout << " std::queue<int> queue; " << std::endl;
    std::queue<int> queue;
    queue.push(5);
    queue.push(4);
    queue.push(1);
    queue.push(3);


    std::cout << " 长度: " << queue.size() << std::endl;
    std::cout << " 遍历 " << std::endl;
    while(!queue.empty()){
        int v = queue.front();
        queue.pop();
        std::cout << v << std::endl;
    }
}

int main(){

    stack();
    list();
    queue();
    return 0;
}
