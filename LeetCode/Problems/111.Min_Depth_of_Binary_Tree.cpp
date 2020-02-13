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
    int min(int a,int b){
        return a<b?a:b;
    }
    int minDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int left = minDepthutil(root->left);
        int right = minDepthutil(root->right);
        if(left==0){
            return right+1;
        }else if(right==0){
            return left+1;
        }
        return min(left,right)+1;
    }
    int minDepthutil(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left = minDepthutil(root->left);
        int right = minDepthutil(root->right);
        return min(left,right)+1;
    }
};
