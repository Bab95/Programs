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
    int pruneTreeutil(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int _left = pruneTreeutil(root->left);
        int _right = pruneTreeutil(root->right);
        if(_left==0){
            TreeNode* leftNode = root->left;
            root->left = NULL;
            delete leftNode;
        }
        if(_right==0){
            TreeNode* rightNode = root->right;
            root->right = NULL;
            delete rightNode;
        }
        return root->val + _left + _right;

    }
    TreeNode* pruneTree(TreeNode* root) {
        pruneTreeutil(root);
        if(!root->left && !root->right && root->val==0){
            return NULL;
        }
        return root;
    }
};
