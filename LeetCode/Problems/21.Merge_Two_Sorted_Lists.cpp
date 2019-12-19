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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* result = NULL;
        ListNode** headref = &result;
        result = merge(l1,l2);
        return result;
    }
    ListNode* merge(ListNode* l1,ListNode* l2){
        if(l1==NULL){
            return l2;
        }else if(l2==NULL){
            return l1;
        }else{
            ListNode* result = NULL;
            if(l1->val<l2->val){
                result = l1;
                result->next = merge(l1->next,l2);
            }else{
                result = l2;
                result->next = merge(l1,l2->next);
            }
            return result;
        }
        return NULL;
    }
};
