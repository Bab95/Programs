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
