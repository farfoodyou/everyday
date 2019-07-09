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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *head,*p,*p1,*p2;
		head = p = newNode(0);
		p1 = l1, p2 = l2;

		SumList(p,l1);
		SumList(p,l2);
		return head;
    }
	void SumList(ListNode *a,ListNode *b){
		ListNode *p = a;
		ListNode *p1 = b;
		while(p1 != NULL){
			addValue(p,p1->val);
			if(p->next!=NULL)p = p->next;
			else if(p1->next!=NULL){
				p->next = newNode(0);
				p=p->next;
			}
			p1 = p1->next;
		}
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
};
