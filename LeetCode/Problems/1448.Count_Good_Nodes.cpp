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
    void dfs(TreeNode* root,int& ans,int max_till_now){
        if(root==NULL){
            return;
        }
        if(!root->left&&!root->right){
            if(root->val>=max_till_now){
                //cout<<max_till_now<<" "<<root->val<<endl;
                ans+=1;
            }
            return;
        }
        if(root->val>=max_till_now){
            ans+=1;
            //cout<<max_till_now<<" "<<root->val<<endl;
            dfs(root->left,ans,root->val);
            dfs(root->right,ans,root->val);
        }else{
            dfs(root->left,ans,max_till_now);
            dfs(root->right,ans,max_till_now);
        }

    }
    int goodNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int max_till_now = root->val;
        int ans = 0;
        dfs(root,ans,max_till_now);
        return ans;
    }
};
