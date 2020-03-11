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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode* p = head;
        ListNode* q = NULL;
        bool flag = false;
        while(p!=NULL){
            flag = false;
            q = p->next;
            while(q!=NULL&&q->val==p->val){
                p->next = q->next;
                delete q;
                q = p->next;
                flag = true;
            }
            if(flag){
                //p is not last node....
                if(p->next){
                    q = p->next;
                    p->val = p->next->val;
                    p->next = q->next;
                    q->next = NULL;
                    delete q;
                }else{
                    //p is the last node....
                    q = head;
                    while(q->next!=NULL&&q->next!=p){
                        q = q->next;
                    }
                    if(q->next==NULL){
                        head=NULL;
                        return head;
                    }
                    q->next = NULL;
                    delete p;
                    break;
                }
            }
            if(!flag)
                p = p->next;
        }
        return head;
    }
};
