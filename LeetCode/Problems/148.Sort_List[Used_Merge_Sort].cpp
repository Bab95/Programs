/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //MERGE SORT USED
class Solution {
public:
    void split(ListNode *head,ListNode **a,ListNode **b){
        ListNode *slow = head,*fast = head->next;
        while(fast!=NULL&&fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        *a = head;
        *b = slow->next;
        slow->next = NULL;
    }
    ListNode* Merge(ListNode* a,ListNode* b){
        ListNode* result = NULL;
        if(a==NULL){
            return b;
        }
        if(b==NULL){
            return a;
        }
        if(a->val<b->val){
            result = a;
            result->next = Merge(a->next,b);
        }else{
            result = b;
            result->next = Merge(a,b->next);
        }
        return result;
    }
    ListNode* MergeSort(ListNode* head){
        if(head->next==NULL){
            return head;
        }
        ListNode* a = NULL;
        ListNode* b = NULL;
        split(head,&a,&b);
        a = MergeSort(a);
        b = MergeSort(b);
        head = Merge(a,b);
        return head;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        return MergeSort(head);
    }
};
