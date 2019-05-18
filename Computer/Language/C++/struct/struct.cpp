#include <cstdio>
#include <cstdlib>
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int v):val(v),next(NULL){}
};
ListNode* mallocNode(int v){
    ListNode* newNode = (ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = v;
    newNode->next = NULL;
    return newNode;
}
ListNode* newNode(int v){
    ListNode* newNode = new ListNode(v);
    return newNode;
}
ListNode* addValue(ListNode* node, int v){
    node->val += v;
    if(node->val>9){
        node->val = node->val % 10;
        if(node->next == NULL){
            node->next = newNode(1);
        } else {
            addValue(node->next,1);
        }
    }
    return node;
}
void SumList(ListNode *a,ListNode *b){
    ListNode *p = a;
    ListNode *p1 = b;
    while(p1 != NULL){
        addValue(p,p1->val);
        if(p->next!=NULL)p = p->next;
        else {
            p->next = newNode(0);
            p=p->next;
        }
        p1 = p1->next;
    }
}
void PrintList(ListNode *p){
    while(p!=NULL){
        printf("%d ",p->val);
        p=p->next;
    }
    printf("\n");
}

int main(){
    ListNode* head = newNode(8);
    ListNode* p = newNode(7);
    ListNode* p2,*p3; 
    PrintList(head);
    SumList(head,p);
    PrintList(head);
    return 0;
}