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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        head = swapPairUtil(head,head->next);
        return head;
    }
    ListNode* swapPairUtil(ListNode* l1,ListNode* l2){
        if(l2==NULL){
            //INCASEOFODD
            return l1;
        }
        if(l2->next==NULL){
            l2->next=l1;
            l1->next = NULL;
            return l2;
        }
        ListNode* tmp = swapPairUtil(l1->next->next,l2->next->next);
        ListNode* result = l2;
        result->next = l1;
        l1->next = tmp;
        return result;

    }
};
