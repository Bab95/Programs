/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        stack<TreeNode*> stk1;
        stack<TreeNode*> stk2;
        TreeNode* c1 = root1;
        TreeNode* c2 = root2;
        while(true){
            while(c1){
                stk1.push(c1);
                c1 = c1->left;
            }
            while(c2){
                stk2.push(c2);
                c2 = c2->left;
            }
            if(!stk1.empty()){
                c1 = stk1.top();
                stk1.pop();
            }
            if(!stk2.empty()){
                c2 = stk2.top();
                stk2.pop();
            }
            if(c1!=NULL&&c2!=NULL){
                if(c1->val<c2->val){
                    ans.push_back(c1->val);
                    stk2.push(c2);
                    c1 = c1->right;
                    c2 = NULL;
                }else{
                    ans.push_back(c2->val);
                    stk1.push(c1);
                    c2 = c2->right;
                    c1 = NULL;
                }
            }else if(c1!=NULL&&c2==NULL){
                ans.push_back(c1->val);
                c1 = c1->right;
            }else if(c1==NULL&&c2!=NULL){
                ans.push_back(c2->val);
                c2 = c2->right;
            }else if(c1==NULL&&c2==NULL){
                return ans;
            }
        }
        return ans;
    }
};
