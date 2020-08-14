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
    void find_sum(TreeNode* root,int c_sum,int sum,int& count){
        if(root==NULL){
            return;
        }
        c_sum = c_sum + root->val;
        find_sum(root->left,c_sum,sum,count);
        if(c_sum==sum){
            count++;
        }
        find_sum(root->right,c_sum,sum,count);
    }
    void preorder(TreeNode* root,int& count,int sum){
        if(root==NULL){
            return;
        }
        find_sum(root,0,sum,count);
        preorder(root->left,count,sum);
        preorder(root->right,count,sum);
    }
    int pathSum(TreeNode* root, int sum) {
        int count = 0;
        preorder(root,count,sum);
        return count;
    }
};
