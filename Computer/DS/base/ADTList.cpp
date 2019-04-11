#include <cstdio>
#include <cstdlib>
#include <iostream>

typedef struct Value{
    int v;
}Value;

typedef struct Node{
    struct Node *next;
    struct Value v;
}Node;

typedef struct ADTList{
    Node *root;
    void InitList(){
        root = (Node *)malloc(sizeof(Node));
        root->next=NULL;
        root->v.v = 0;
    }
    void DestroyList(){
        // 初始化有关的知识, 初始化不是在函数调用的时候才初始化的么? 不是这个情况.
        // Node *p,*q = root;  我怎么能写出这么蠢的写法
        Node *p,*q;
        p = q = root;
        root = NULL;
        while(p->next != NULL){
            q = p->next; 
            free(p);
            p = q;
        }
    }
    int ListLength(){
        int len = -1;
        Node *p = root;
        while(p != NULL){
            len++;
            p = p->next;
        }
        return len;
    }
    Node* Head(){
        return root;
    }
    Node* Tail(){
        Node *p = root;
        while(p->next != NULL){
            p = p->next;
        }
        return p;
    }
    void PrintList(){
        Node *p = root;
        while(p->next != NULL){
            printf("%d\n",p->v.v);
            p = p->next;
        }
        printf("%d\n",p->v.v);
    }
    int IsEmpty(){
        Node* t = Tail();
        if (root != t) {
            return 1;
        }
        return 0;
    }
    void ListInsert(Value v){
        Node *p = Tail();
        p->next = (Node *)malloc(sizeof(Node));
        p = p->next;
        (*p).v = v;
        p->next = NULL;
        printf("insert %d\n",v.v);
    }
    void hi();
}List;
void List::hi(){
    printf("hi, this is a struct list\n");
}
int main(){
    List list;
    list.hi();
    list.InitList();
    Value v;
    v.v = 123;
    list.ListInsert(v);
    v.v = 33;
    list.ListInsert(v);
    Node *t = list.Tail();
    std::cout << list.ListLength() << std::endl;
    std::cout << "node tail"<< std::endl;

    // 
    [](int v)->int{printf("lambda %d\n",v);return 0;}(8899);

    v.v = 567;
    list.ListInsert(v);
    t = list.Tail();
    std::cout << "node tail: " << t->v.v << std::endl;
    list.PrintList();

    //std::cout << t->v.v << std::endl;
    list.DestroyList();

    return 0;
}