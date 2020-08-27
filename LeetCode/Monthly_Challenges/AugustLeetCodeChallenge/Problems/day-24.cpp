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
    bool is_leaf(TreeNode* root){
        if(root->left==NULL && root->right==NULL){
            return true;
        }
        return false;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        if(is_leaf(root)){
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int sum = 0;
        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();
            if(current->left&&is_leaf(current->left)){
                sum += current->left->val;
            }
            if(current->left){
                q.push(current->left);
            }
            if(current->right){
                q.push(current->right);
            }
        }
        return sum;
    }
};
