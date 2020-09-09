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
    TreeNode* deleteNode(TreeNode* root,int key){
        root = _deleteNode(root,key);
        return root;
    }
    TreeNode* _deleteNode(TreeNode* root, int key) {
        if(!root){
            return NULL;
        }
        if(root->val==key){
            if(root->left){
                TreeNode* Y = root->right;
                root->val = root->left->val;
                TreeNode* Node = root->left;
                root->left = Node->left;
                root->right = Node->right;
                TreeNode* current = root;
                while(current->right!=NULL){
                    current = current->right;
                }
                current->right = Y;
                delete Node;
                return root;
            }else if(root->right){
                TreeNode* Node = root;
                root = root->right;
                delete Node;
                return root;
            }else if(!root->left&&!root->right){
                delete root;
                return NULL;
            }
        }else if(root->val<key){
            root->right = _deleteNode(root->right,key);
        }else if(root->val>key){
            root->left = _deleteNode(root->left,key);
        }
        return root;
    }
};
