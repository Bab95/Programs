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
    int inorder_Successor(TreeNode* root){
        root = root->right;
        while(root&&root->left){
            root = root->left;
        }
        return root->val;
    }
    TreeNode* delete_node(TreeNode* root,int key){
        if(root==NULL){
            return root;
        }
        if(key>root->val){
            root->right = delete_node(root->right,key);
        }else if(key<root->val){
            root->left = delete_node(root->left,key);
        }else{
            if(root->left==NULL){
                TreeNode* tmp = root->right;
                delete root;
                return tmp;
            }else if(root->right==NULL){
                TreeNode* tmp = root->left;
                delete root;
                return tmp;
            }
                //both children present so find inorder successor....
                root->val = inorder_Successor(root);
                root->right = delete_node(root->right,root->val);
            return root;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        root = delete_node(root,key);
        return root;
    }
};
