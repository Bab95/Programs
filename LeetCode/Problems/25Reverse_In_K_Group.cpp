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
    int count(ListNode* head){
        ListNode* p = head;
        int res = 0;
        while(p!=NULL){
            p = p->next;
            res++;
        }
        return res;
    }
    ListNode* reverseKGroup(ListNode* head,int k){
        int c = count(head);
        if(c<k){
            return head;
        }
        else{
            return reverseKGroupUtil(head,k,c);
        }
        return NULL;
    }
    ListNode* reverseKGroupUtil(ListNode* head, int k,int c) {
        if(c<0||c<k){
            return head;
        }
        if(k==1){
            return head;
        }
        ListNode* next;
        ListNode* current = head;
        ListNode* prev = NULL;
        int i = 0;
        while(current!=NULL&&i<k){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            i++;
        }
        if(next!=NULL){
            head->next = reverseKGroupUtil(next,k,c-k);
        }
        return prev;
    }
};
