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
        ListNode* del;
        ListNode* p;
        del = head;
        p = head;
        ListNode* tmp;
        for(int i=0;i<n;++i){
            p = p->next;
        }
        while(p!=NULL&&p->next!=NULL){
            del = del->next;
            p = p->next;
        }
        if(p==NULL){
            tmp = head;
            head = head->next;
            delete tmp;
            return head;
        }
        tmp = del->next;
        del->next = (del->next!=NULL)?del->next->next:NULL;
        delete tmp;
        return head;
    }
};
