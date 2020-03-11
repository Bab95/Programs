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
    ListNode* partition(ListNode* head, int x) {
        ListNode* prev = NULL;
        ListNode* node = head;
        ListNode* ans = NULL;
        ListNode* q = NULL;
        ListNode* ptr = NULL;
        while(node!=NULL){
            if(node->val<x){
                if(prev==NULL){
                    head = head->next;
                    node->next = NULL;
                    if(ans==NULL){
                        ans = node;
                        q = ans;
                    }else{
                        q->next = node;
                        q = q->next;
                    }
                    node = head;
                }else{
                    prev->next = node->next;
                    node->next = NULL;
                    if(ans==NULL){
                        ans = node;
                        q = ans;
                    }else{
                        q->next = node;
                        q = q->next;
                    }
                    node = prev->next;
                }

            }else{
                prev = node;
                node = node->next;
            }
        }
        if(ans==NULL){
            return head;
        }else{
            q->next = head;
            head = ans;
        }
        return head;
    }
};
