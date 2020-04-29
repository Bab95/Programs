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
    void inorder(TreeNode* root,int* val){
        if(root==NULL){
            return;
        }
        if(root->right){
            inorder(root->right,val);
        }
        *val += root->val;
        root->val = *val;
        if(root->left){
            inorder(root->left,val);
        }
    }
    TreeNode* bstToGst(TreeNode* root) {
        int val = 0;
        inorder(root,&val);
        return root;
    }

};
