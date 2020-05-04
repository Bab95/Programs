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
    void find(TreeNode*root,int *ans){
        if(root==NULL){
            return;
        }
        if(root->left==NULL&&root->right==NULL){
            return;
        }
        /*if(root->left->left==NULL&&root->left->right==NULL&&root->right->left==NULL&&root->right->right==NULL){
            return;
        }*/
        if(root->val%2==0){
            if(root->left&&root->left->left){
                *ans = *ans + (root->left->left->val);
            }

            if(root->left&&root->left->right){
                *ans = *ans + (root->left->right->val);
            }

            if(root->right&&root->right->left){
                *ans = *ans + (root->right->left->val);
            }

            if(root->right&&root->right->right){
                *ans = *ans + (root->right->right->val);
            }
        }

        find(root->left,ans);
        find(root->right,ans);
    }
    int sumEvenGrandparent(TreeNode* root) {
        int ans = 0;
        find(root,&ans);
        return ans;
    }
};
