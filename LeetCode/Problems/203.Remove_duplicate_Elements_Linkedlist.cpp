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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* p = head;
        /*if(head->val==val){
            p = head;

        }*/
        if(head==NULL){
            return head;
        }
        ListNode* tmp = NULL;
        while(p&&p->next){
           if(p->next->val==val){
               tmp = p->next;
               p->next = tmp->next;
               tmp->next = NULL;
               delete tmp;
           }else{
                p = p->next;
           }
        }
        label:
        if(head!=NULL&&head->val==val){
            cout<<"en"<<endl;
            if(head->next==NULL){
                return NULL;
            }
            tmp = head;
            head = head->next;
            tmp->next = NULL;
            delete tmp;
            goto label;
        }
        return head;
    }
};
