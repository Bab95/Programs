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
    void getNumberUtil(int *ans,int power,ListNode* head,int *i){
        if(head==NULL){
            return;
        }
        *i = *i+1;
        getNumberUtil(ans,power+1,head->next,i);
        *ans = *ans + (head->val)*(int)pow(2,(*i)-power-1);
        //*i = *i+1;
        return;

    }
    int getDecimalValue(ListNode* head) {
        int i = 0;
        int ans = 0;
        getNumberUtil(&ans,0,head,&i);
        return ans;
    }
};
