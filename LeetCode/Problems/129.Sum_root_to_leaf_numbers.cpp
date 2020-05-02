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
    int number(vector<int>& nums){
        int result = 0;
        for(int i=0;i<nums.size();++i){
            result = result*10+nums[i];
        }
        return result;
    }
    bool isleaf(TreeNode* root){
        if(root==NULL){
            return false;
        }
        if(root->left==NULL&&root->right==NULL){
            return true;
        }
        return false;
    }
    void findnumber(TreeNode* root,vector<int>& nums,int& ans){
        if(root==NULL){
            return;
        }
        if(isleaf(root)){
            nums.push_back(root->val);
            ans+=number(nums);
            nums.pop_back();
            return;
        }
        nums.push_back(root->val);
        findnumber(root->left,nums,ans);
        findnumber(root->right,nums,ans);
        nums.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        vector<int> nums;
        int ans = 0;
        findnumber(root,nums,ans);
        return ans;
    }
};
