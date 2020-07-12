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
        if(head==NULL){
            return head;
        }
        ListNode* p = head;
        while(n>1&&p!=NULL){
            p = p->next;
            n--;
        }
        ListNode* q = head;
        ListNode* prev = NULL;
        while(p->next!=NULL){
            prev = q;
            q = q->next;
            p = p->next;
        }
        if(prev==NULL){
            //first node to be deleted...
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
            return head;
        }
        if(prev!=NULL){
            ListNode* tmp = prev->next;
            if(prev->next!=NULL){
                prev->next = prev->next->next;
                delete tmp;
            }
        }
        return head;
    }
};
/*
[1,2,3,4,5]
5
[1,2,3,4,5]
4
[1,2,3,4,5]
3
[1,2,3,4,5]
2
[1,2,3,4,5]
1
[1,2,3,4,5,6]
4
*/
