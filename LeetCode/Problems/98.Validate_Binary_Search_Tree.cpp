/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <limits.h>
class Solution {
public:
    bool isValid(TreeNode* root,long long int _min,long long int _max){
        if(root==NULL){
            return true;
        }
        /*if(root->left==NULL&&root->right==NULL){
            return (root->val>_min)&&(root->val<_max);
        }*/
        if(root->val>_min&&root->val<_max){
            return isValid(root->left,_min,root->val)&&isValid(root->right,root->val,_max);
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        long long int _min = -2147483649;
        long long int _max = 2147483649;
        return isValid(root,_min,_max);
    }
};
