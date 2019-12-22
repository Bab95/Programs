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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *q=NULL,*tmp;
        ListNode *prev = NULL;
        tmp = head;
        for(int i=0;i<n;i++){
            tmp = tmp->next;
        }
        /*if(tmp==NULL){
            return NULL;
        }*/
        q = head;
        while(tmp!=NULL){
            prev = q;
            tmp = tmp->next;
            q = q->next;
        }
        if(prev!=NULL){
            prev->next = q->next;
            delete q;
        }
        if(prev==NULL){
            q = head;
            head = head->next;
            delete q;
        }
        return head;
    }
};
