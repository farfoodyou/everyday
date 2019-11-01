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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) {
            return l2;
        }
        if(!l2) {
            return l1;
        }
        
        ListNode *p, *q;
        p = l1; q = l2;
        ListNode* mydump = NULL, *newtail;
        if(l1->val < l2->val) {
            mydump = l1;
            p = p->next;
        } else {
            mydump = l2;
            q = q->next;
        }
        newtail = mydump;
        while(p || q){
            if(p && q) {
               if(p->val < q->val) {
                    newtail->next = p;
                    p = p->next;
                } else {
                    newtail->next = q;
                    q = q->next;
                }
            } else if(!q) {
                newtail->next = p;
                break;
            } else if(!p) {
                newtail->next = q;
                break;
            }
            newtail = newtail->next;
            std::cout << newtail->val << "\n";
        }
        return mydump;
    }


        ListNode* mergeTwoListsR(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        else if (l2 == NULL) return l1;
        else if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }

};

