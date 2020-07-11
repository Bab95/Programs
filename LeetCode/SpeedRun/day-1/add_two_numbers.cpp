/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL){
            return l2;
        }
        if(l2==NULL){
            return l1;
        }
        ListNode* result = NULL;
        ListNode* q = NULL;
        int carry = 0;
        while(l1!=NULL || l2!=NULL){
            int a = (l1!=NULL)?l1->val:0;
            int b = (l2!=NULL)?l2->val:0;
            int sum = a+b+carry;
            carry = sum/10;
            sum = sum%10;
            if(result==NULL){
                result = new ListNode(sum);
                q = result;
            }else{
                q->next = new ListNode(sum);
                q = q->next;
            }
            l1 = (l1!=NULL)?l1->next:NULL;
            l2 = (l2!=NULL)?l2->next:NULL;
        }
        if(carry!=0){
            q->next = new ListNode(carry);
        }
        return result;
    }
};
