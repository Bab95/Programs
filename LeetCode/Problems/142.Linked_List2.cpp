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
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL){
            return NULL;
        }
        /*ListNode *slow,*fast;
        slow = head;
        fast = head;
        while(slow!=NULL&&fast!=NULL&&fast->next!=NULL&&fast->next!=slow){
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast!=NULL&&fast->next==slow){
            return fast;
        }
        return NULL;*/
        map<ListNode*,ListNode*> par_child;
        par_child[head] = NULL;
        par_child[head->next] = head;
        ListNode *p = head->next;
        while(p!=NULL){
            if(p!=NULL&&p->next!=NULL&&par_child.find(p->next)!=par_child.end()){
                /*for(map<ListNode*,ListNode*>::iterator itr=par_child.begin();itr!=par_child.end();itr++){
                       cout<<itr->first->val<<" "<<itr->second->val<<endl;
                }*/
                return p->next;
            }
            par_child[p->next] = p;
            p = p!=NULL?p->next:NULL;
        }
        /*for(map<ListNode*,ListNode*>::iterator itr=par_child.begin();itr!=par_child.end();itr++){
            cout<<itr->first->val<<" "<<itr->second->val<<endl;
        }*/
        return NULL;
    }
};
