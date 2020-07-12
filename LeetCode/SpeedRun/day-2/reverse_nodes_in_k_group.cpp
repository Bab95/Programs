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
    int count_nodes(ListNode* p){
        int res = 0;
        while(p!=NULL){
            p = p->next;
            res++;
        }
        return res;
    }
    ListNode* reverse(ListNode* head,int k,int count){
        if(k>count||k==1){
            return head;
        }
        int i = 0;
        ListNode* prev = NULL;
        ListNode* next;
        ListNode* current = head;
        while(current!=NULL&&i<k){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            ++i;
        }
        if(next!=NULL){
            head->next = reverse(next,k,count-k);
        }

        return prev;

    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1){
            return head;
        }
        int count = count_nodes(head);
        head = reverse(head,k,count);
        return head;
    }
};
