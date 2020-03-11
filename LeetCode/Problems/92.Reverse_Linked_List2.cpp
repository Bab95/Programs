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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int i = 0;
        ListNode* s_prev = NULL;
        ListNode* start = head;
        ListNode *ptr,*next,*prev=NULL;
        /*if(m==1){
            goto label;
        }*/
        while(i<m-1){
            s_prev = start;
            start = start->next;
            i++;
        }
        //label:
        ptr = start;
        i = 0;
        while(ptr!=NULL&&i<=(n-m)){
            i++;
            next = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = next;
        }
        if(s_prev==NULL){
            head->next = next;
            head = prev;
        }else{
            s_prev->next = prev;
            start->next = next;
        }
        return head;
    }
};
