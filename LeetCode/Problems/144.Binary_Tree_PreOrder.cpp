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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root==NULL){
            return result;
        }
        TreeNode* current = root;
        stack<TreeNode*> stk;
        stk.push(current);
        while(!stk.empty()){
            current = stk.top();
            stk.pop();
            if(current->right!=NULL){
                stk.push(current->right);
            }
            result.push_back(current->val);
            if(current->left!=NULL){
                stk.push(current->left);
            }
        }
        return result;
    }
};
