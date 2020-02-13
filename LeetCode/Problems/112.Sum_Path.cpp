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
    bool sumPath(TreeNode* root,int sum,int current_sum){
        if(root==NULL){
            return false;
        }
        if(root->left==NULL&&root->right==NULL){
            if(sum==current_sum+root->val){
                return true;
            }else{
                return false;
            }
        }
        bool inleft = (root->left==NULL)?false:(sumPath(root->left,sum,current_sum+root->val));
        bool inright = (root->right==NULL)?false:(sumPath(root->right,sum,current_sum+root->val));
        return inleft||inright;
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL){
            return false;
        }
        return sumPath(root,sum,0);
    }
};
