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
    bool is_leaf(TreeNode* root){
        if(root==NULL){
            return false;
        }
        if(root->left==NULL&&root->right==NULL){
            return true;
        }
        return false;
    }
    void dfs(TreeNode* root,int& ans,int m){
        if(root==NULL){
            return;
        }
        m = m<<1;
        if(root->val==1){
            m = m | 1;
        }
        if(is_leaf(root)){
            ans+=m;
            cout<<m<<" ";
            return;
        }
        dfs(root->left,ans,m);
        dfs(root->right,ans,m);
    }
    int sumRootToLeaf(TreeNode* root) {
        int m = 0;
        int ans = 0;
        dfs(root,ans,m);
        return ans;
    }
};
