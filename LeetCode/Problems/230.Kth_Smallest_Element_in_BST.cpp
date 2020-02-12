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
    void my_inorder(TreeNode* root,int *i,int k,int *result){
        if(root==NULL){
            return;
        }
        my_inorder(root->left,i,k,result);
        *i = *i+1;
        if(*i==k){
            *result = root->val;
            return;
        }
        my_inorder(root->right,i,k,result);
    }
    int kthSmallest(TreeNode* root, int k) {
        int i = 0;
        int result=-1;
        my_inorder(root,&i,k,&result);
        if(result!=-1){
            return result;
        }
        return result;
    }
};
