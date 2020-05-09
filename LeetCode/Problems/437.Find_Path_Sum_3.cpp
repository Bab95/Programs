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
    void print(vector<int>& path){
        for(int x : path){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    void findSum(TreeNode* root,int sum,int current,int& ans){
        if(root==NULL){
            return;
        }
        current = current+root->val;
        if(current==sum){
            ans+=1;
        }
        findSum(root->left,sum,current,ans);
        findSum(root->right,sum,current,ans);
    }
    void preorder(TreeNode* root,int sum,int& ans){
        if(root==NULL){
            return;
        }
        int current = 0;
        findSum(root,sum,current,ans);
        preorder(root->left,sum,ans);
        preorder(root->right,sum,ans);
    }
    int pathSum(TreeNode* root, int sum) {
        int ans = 0;
        int current = 0;
        preorder(root,sum,ans);
        return ans;
    }
};
