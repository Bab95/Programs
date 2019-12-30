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
    int count(ListNode* p){
        int res = 0;
        while(p!=NULL){
            p = p->next;
            res++;
        }
        return res;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        /*if(head==NULL){
            return NULL;
        }*/
        int length = count(head);
        if(k==0||k==length||head==NULL||head->next==NULL){
            return head;
        }
        ListNode* tmp = head;

        if(k>length){
            k = k%length;
            if(k==0){
                return head;
            }
        }
        for(int i=0;i<k-1;i++){
            tmp = tmp->next;
        }
        ListNode* q = head;
        ListNode* prev = NULL;
        while(tmp->next!=NULL){
            prev = q;
            q = q->next;
            tmp = tmp->next;
        }
        ListNode* newhead = q;
        prev->next = NULL;
        tmp->next = head;
        return newhead;
    }
};
