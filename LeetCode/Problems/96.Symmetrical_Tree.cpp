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
    bool isSymmetric(TreeNode* root) {
        return isSym(root,root);
    }
    bool isSym(TreeNode* r1,TreeNode* r2){
        if(r1==NULL&&r2==NULL){
            return true;
        }
        if((r1==NULL&&r2!=NULL)||(r1!=NULL&&r2==NULL)){
            return false;
        }
        if(r1->val!=r2->val){
            return false;
        }
        if(r1->val==r2->val){
            return isSym(r1->left,r2->right)&&isSym(r1->right,r2->left);
        }
        return true;
    }
};
