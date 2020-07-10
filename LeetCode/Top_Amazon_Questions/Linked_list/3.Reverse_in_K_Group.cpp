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
    int count(ListNode* head){
        int res = 0;
        while(head){
            res++;
            head = head->next;
        }
        return res;
    }
    ListNode* reverse(ListNode* head,int k,int count){
        if(count<k){
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
            ++i;
        }
        if(next!=NULL){
            head->next = reverse(next,k,count-k);
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int nodes = count(head);
        if(nodes<k){
            return head;
        }
        return reverse(head,k,nodes);
    }
};
