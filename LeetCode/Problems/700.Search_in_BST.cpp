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
    void Search(TreeNode* root,int val,TreeNode** result){
        if(root==NULL){
            return;
        }
        if(root->val==val){
            *result = root;
            return;
        }else if(root->val>val){
            Search(root->left,val,result);
        }else{
            Search(root->right,val,result);
        }
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* result = NULL;
        Search(root,val,&result);
        return result;
    }
};
