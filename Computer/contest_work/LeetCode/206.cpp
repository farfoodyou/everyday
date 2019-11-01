/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head ==NULL){
            return NULL;
        }
        ListNode* tmp = rear(head);
        ListNode* newRear = _reverseList(head);
        newRear->next = NULL;
        return tmp;
    }
    ListNode* rear(ListNode* head){
        ListNode* p = head;
        while(p->next){
            p = p->next;
        }
        return p;
    }
    ListNode* _reverseList(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        std::cout << head->val << " \n";
        if(head->next == NULL){
            return head;
        }
        ListNode* tmp = _reverseList(head->next);
        tmp->next = head;
        return head;
    }

    
    ListNode* stackSolve(ListNode* head) {
        if(head == NULL) {
            return NULL;
        }
        std::stack<ListNode* > st;
        ListNode* p = head;
        while(p->next){
            st.push(p);
            p = p->next;
        }
        ListNode *newHead = p;
        ListNode *tmp = NULL;
        while(!st.empty()){
            tmp = st.top();
            st.pop();
            p->next = tmp;
            p = p->next;
        }
        if(tmp)tmp->next = NULL;
        return newHead;
    }
};