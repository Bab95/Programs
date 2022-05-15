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
    void inorder(TreeNode* root, TreeNode** prev, TreeNode** head){
        if (root == NULL){
            return;
        }
        inorder(root->left, prev, head);
        if (*head == NULL){
            *head = root;
            *prev = root;
        }else{
            (*prev)->right = root;
            root->left = NULL;
            (*prev)->left = NULL;
            *prev = root;
        }
        inorder(root->right, prev, head);
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* head = NULL;
        TreeNode* prev = NULL;
        inorder(root, &prev, &head);
        return head;
    }
};