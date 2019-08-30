#include <cstdio>
#include <iostream>

typedef struct node {
    int k;
    int v;
} node;

typedef std::shared_ptr<node> NodePtr;

int main(){
    node a;
    NodePtr node_ptr = std::make_shared<node>();

    std::cout << a.k << std::endl;
    std::cout << node_ptr->k << std::endl;

}