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
    bool leaf(TreeNode* root){
        if(root==NULL){
            return false;
        }
        if(root->left==NULL&&root->right==NULL){
            return true;
        }
        return false;
    }
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }
        if(leaf(root)){
            return root;
        }
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        root->left = invertTree(root->left);
        root->right = invertTree(root->right);
        return root;
    }
};
