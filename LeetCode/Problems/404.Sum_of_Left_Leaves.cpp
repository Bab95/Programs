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
        if(!root->left&&!root->right){
            return true;
        }
        return false;
    }
    void findSum(TreeNode* root,int* ans){
        if(root==NULL){
            return;
        }
        if(root->left&&leaf(root->left)){
            *ans = *ans + root->left->val;
        }
        findSum(root->left,ans);
        findSum(root->right,ans);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        findSum(root,&ans);
        return ans;
    }
};
