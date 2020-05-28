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
    int result = INT_MIN;
    int dfs(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left = dfs(root->left);
        int right = dfs(root->right);
        result = max(root->val+left+right,result);
        return max(0,root->val+max(left,right));
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return result;
    }
};
