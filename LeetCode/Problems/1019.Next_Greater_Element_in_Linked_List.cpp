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
    void nextLargeUtil(ListNode* head,vector<int>& result,stack<int>& stk){
        if(head->next==NULL){
            result.push_back(0);
            stk.push(head->val);
            return;
        }
        nextLargeUtil(head->next,result,stk);
        if(!stk.empty()&&head->val<stk.top()){
            result.push_back(stk.top());
            stk.push(head->val);
        }else if(!stk.empty()&&head->val>=stk.top()){
            while(!stk.empty()&&head->val>=stk.top()){
                stk.pop();
            }
            if(stk.empty()){
                result.push_back(0);
                stk.push(head->val);
            }else{
                result.push_back(stk.top());
                stk.push(head->val);
            }
        }else if(stk.empty()){
            result.push_back(0);
            stk.push(head->val);
        }
    }
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> result;
        if(head==NULL){
            return result;
        }
        stack<int> stk;
        nextLargeUtil(head,result,stk);
        int l = 0;
        int r = result.size()-1;
        while(l<r){
            int tmp = result[l];
            result[l] = result[r];
            result[r] = tmp;
            l++;
            r--;
        }
        return result;
    }
};
