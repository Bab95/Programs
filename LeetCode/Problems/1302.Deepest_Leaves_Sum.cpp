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
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return max(height(root->left),height(root->right))+1;
    }
    void find(TreeNode* root,int h,int current,int* ans){
        if(root==NULL){
            return;
        }
        if(current==h){
            *ans = *ans+root->val;
        }
        find(root->left,h,current+1,ans);
        find(root->right,h,current+1,ans);
    }
    int deepestLeavesSum(TreeNode* root) {
        int h = height(root);
        cout<<h<<endl;
        int ans = 0;
        find(root,h,1,&ans);
        return ans;
    }
};
