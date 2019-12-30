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
    int max(int a,int b){
        return a>b?a:b;
    }
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return 1+max(height(root->left),height(root->right));
    }
    int mod(int x){
        if(x<0){
            return -1*x;
        }
        return x;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        int left = height(root->left);
        int right = height(root->right);
        if(mod(left-right)<=1){
            return isBalanced(root->left)&&isBalanced(root->right);
        }
        return false;
    }
};
