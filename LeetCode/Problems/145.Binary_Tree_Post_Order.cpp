/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root==NULL){
            return result;
        }
        stack<TreeNode*> stk;
        stk.push(root);
        TreeNode* current = NULL;
        while(!stk.empty()){
            current = stk.top();
            stk.pop();
            result.push_back(current->val);
            if(current->left){
                stk.push(current->left);
            }
            if(current->right){
                stk.push(current->right);
            }
        }
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
