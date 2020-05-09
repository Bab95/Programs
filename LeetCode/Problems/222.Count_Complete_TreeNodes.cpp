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
    int count(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        if(!root->left&&!root->right){
            return 1;
        }
        int left = count(root->left);
        int right = count(root->right);
        return left+right+1;
    }
    int countNodes(TreeNode* root) {
        int ans = count(root);
        return ans;
    }
};
