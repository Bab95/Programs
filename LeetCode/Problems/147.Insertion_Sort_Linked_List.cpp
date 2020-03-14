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
    int length(ListNode *p){
        int len = 0;
        while(p!=NULL){
            p = p->next;
            len++;
        }
        return len;
    }
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode *p = head,*q = head;
        ListNode *sorted = head;
        bool flag = false;
        int i = 0;
        int len = length(head);
        //cout<<len<<endl;
        bool sorted_increment = false;
        while(sorted!=NULL&&i<len){
            i++;
            q = sorted->next;
            if(q==NULL){
                break;
            }
            flag = false;
            ListNode *prev = sorted;
            while(q!=NULL&&q->val>sorted->val){
                prev = q;
                q = q->next;
            }
            if(q!=NULL){
                prev->next = q->next;
                q->next = NULL;
                flag = true;
            }else{
                sorted = sorted->next;
                continue;
            }
            if(flag){
                p = head;
                ListNode *qrev = NULL;
                while(p!=NULL&&p!=sorted&&q->val>p->val){
                    qrev = p;
                    p = p->next;
                }
                if(qrev==NULL){
                    q->next = head;
                    head = q;
                }else{
                    q->next = p;//qrev->next;
                    qrev->next = q;
                }
            }
           //sorted = sorted->next;
        }
        return head;
    }
};
