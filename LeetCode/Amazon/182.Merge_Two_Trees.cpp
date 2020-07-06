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
    TreeNode* merge(TreeNode* t1,TreeNode* t2){
        if(t1==NULL&&t2==NULL){
            return NULL;
        }
        if(t1!=NULL&&t2!=NULL){
            TreeNode* root = new TreeNode(t1->val+t2->val);
            root->left = merge(t1->left,t2->left);
            root->right = merge(t1->right,t2->right);
            return root;
        }else if(t1==NULL){
            TreeNode* root = new TreeNode(t2->val);
            root->left = merge(t1,t2->left);
            root->right = merge(t1,t2->right);
            return root;
        }
        else if(t2==NULL){
            TreeNode* root = new TreeNode(t1->val);
            root->left = merge(t1->left,t2);
            root->right = merge(t1->right,t2);
            return root;
        }
        return NULL;
    }
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode* result = merge(t1,t2);
        return result;
    }
};
