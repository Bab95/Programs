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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* successor;
        if(p->right){
            successor = p->right;
            while(successor->left){
                successor = successor->left;
            }
            return successor;
        }
        TreeNode* next = NULL;
        TreeNode* current = root;
        while(current!=NULL){
            if(current==p){
                return next;
            }else if(p->val<current->val){
                next = current;
                current = current->left;
            }else{
                current = current->right;
            }
        }
        return next;
    }
};
