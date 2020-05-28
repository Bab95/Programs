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
    void inorder(TreeNode* root,int& result,int& count,int k){
        if(root==NULL){
            return;
        }
        inorder(root->left,result,count,k);
        count++;
        if(count==k){
            result = root->val;
            return;
        }
        inorder(root->right,result,count,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int result = INT_MIN;
        int count = 0;
        inorder(root,result,count,k);
        return result;
    }
};
