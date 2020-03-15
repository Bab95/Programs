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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL||head->next==NULL||head->next->next==NULL){
            return head;
        }
        ListNode *odd = head,*even = head->next;
        ListNode *e_start = head->next;
        ListNode *q = NULL;
        while(even!=NULL&&even->next!=NULL){
            q = even->next;
            even->next = even->next->next;
            q->next = e_start;
            odd->next = q;
            odd = odd->next;
            even = even->next;
        }
        return head;
    }
};
