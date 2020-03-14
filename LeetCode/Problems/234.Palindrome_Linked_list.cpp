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
    void split(ListNode* head,ListNode **a,ListNode **b){
        ListNode *slow = head,*fast = head->next;
        while(fast!=NULL&&fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        *a = head;
        *b = slow->next;
        slow->next = NULL;
        return;
    }
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode *ptr=head,*prev=NULL,*next;
        while(ptr!=NULL){
            next = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = next;
        }
        head = prev;
        return head;
    }
    int length(ListNode *p){
        int len = 0;
        while(p!=NULL){
            p = p->next;
            len++;
        }
        return len;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL){
            return true;
        }
        int len = length(head);
        ListNode *a = NULL,*b = NULL;
        split(head,&a,&b);
        b = reverseList(b);
        while(a!=NULL&&b!=NULL){
            if(a->val!=b->val){
                return false;
            }
            a = a->next;
            b = b->next;
        }
        return true;
    }
};
