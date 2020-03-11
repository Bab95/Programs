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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode* p = head;
        ListNode* q;
        while(p!=NULL){
            q = p->next;
            while(q!=NULL&&q->val==p->val){
                p->next = q->next;
                delete q;
                q = p->next;
            }
            if(p!=NULL){
                p = p->next;
            }
        }
        return head;
    }
};
