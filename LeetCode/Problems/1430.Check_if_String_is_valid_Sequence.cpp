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
    bool leaf(TreeNode* root){
        if(root==NULL){
            return false;
        }
        if(root->left==NULL&&root->right==NULL){
            return true;
        }
        return false;
    }
    bool preorder(TreeNode* root,vector<int>& arr,int index){
        if(root==NULL&&index<arr.size()){
            return false;
        }
        if(index==arr.size()-1&&leaf(root)){
            if(root->val==arr[index])
                return true;
            else{
                return false;
            }
        }else if(index==arr.size()-1&&!leaf(root)){
            return false;
        }
        if(root->val==arr[index]){
            bool left = preorder(root->left,arr,index+1);
            bool right = preorder(root->right,arr,index+1);
            return left||right;
        }
        return false;
    }
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        return preorder(root,arr,0);
    }
};
