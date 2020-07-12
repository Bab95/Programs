/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode* p = head;
        ListNode* result = NULL;
        ListNode* q = NULL;
        while(p!=NULL&&p->next!=NULL){
            ListNode* Next = p->next->next;
            ListNode* tmp1 = p->next;
            p->next = Next;
            tmp1->next = p;
            p = tmp1;
            if(result==NULL){
                result = p;
                q = p->next;
            }else{
                q->next = p;
                q = p->next;
            }
            p = Next;
        }
        return result;
    }
};
