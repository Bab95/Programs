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
        ListNode* p = l1;
        ListNode* q = l2;
        int carry = 0;
        ListNode* result = NULL;
        ListNode* r = NULL;
        while (p || q) {
            int a = 0, b = 0;
            if (p) {
                a = p->val;
                p = p->next;
            }
            if (q) {
                b = q->val;
                q = q->next;
            }
            int sum = b + a + carry;
            carry = sum / 10;
            sum = sum % 10;
            if (result == NULL) {
                result = new ListNode(sum);
                r = result;
            } else {
                r->next = new ListNode(sum);
                r = r->next;
            }
        }
        if (carry != 0) {
            r->next = new ListNode(carry);
        }
        return result;
    }
};
