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
    void inorder(TreeNode* root,vector<TreeNode*>& inorderHolder){
        if(root==NULL){
            return;
        }
        inorder(root->left,inorderHolder);
        inorderHolder.push_back(root);
        inorder(root->right,inorderHolder);
    }
    void minorder(TreeNode* root){
        if(root==NULL){
            return;
        }
        minorder(root->left);
        cout<<root->val<<" ";
        minorder(root->right);
    }
    TreeNode* convertBST(TreeNode* root) {
        vector<TreeNode*> inorderHolder;
        inorder(root,inorderHolder);
        for(int i=inorderHolder.size()-2;i>=0;i--){
            inorderHolder[i]->val = inorderHolder[i]->val + inorderHolder[i+1]->val;
        }
        //minorder(root);
        return root;

    }
};
