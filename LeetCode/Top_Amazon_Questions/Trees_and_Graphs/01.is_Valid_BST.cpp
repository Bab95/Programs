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
    bool isvalid(TreeNode* root,long int min,long int max){
        if(root==NULL){
            return true;
        }
        if(root->val>min&&root->val<max){
            return isvalid(root->left,min,root->val)&&isvalid(root->right,root->val,max);
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        long int a = (long int)INT_MIN;
        a -= 1;
        long int b = (long int)INT_MAX;
        b += 1;
        return isvalid(root->left,a,root->val)&&isvalid(root->right,root->val,b);
    }
};
