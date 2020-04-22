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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = NULL;
        ListNode* q = NULL;
        ListNode *h1 = l1;
        ListNode *h2 = l2;
        int carry = 0;
        while(h1||h2||carry){
            int a = (h1!=NULL)?h1->val:0;
            int b = (h2!=NULL)?h2->val:0;
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
            if(h1){
                h1 = h1->next;
            }
            if(h2){
                h2 = h2->next;
            }
        }
        /*if(carry){
            q->next = new ListNode(carry);
        }*/
        return result;
    }
};
