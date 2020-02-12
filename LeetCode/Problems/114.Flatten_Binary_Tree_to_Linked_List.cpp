/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <stack>
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==NULL){
            return;
        }
        stack<TreeNode*> s;
        TreeNode* head = NULL;
        TreeNode*q = NULL;
        s.push(root);
        while(!s.empty()){
            root = s.top();
            s.pop();
            if(root->right){
                s.push(root->right);
            }
            if(root->left){
                s.push(root->left);
            }
            if(head==NULL){
                head = root;
                q = head;
                q->left = NULL;
                q->right = NULL;
            }else{
                q->right = root;
                q = q->right;
                q->left = NULL;
            }
        }
        root = head;
    }
};
