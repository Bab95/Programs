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
    bool leaf(TreeNode* root){
        if(root==NULL){
            return false;
        }
        if(!root->left&&!root->right){
            return true;
        }
        return false;
    }
    void findPath(TreeNode* root,string path,vector<string>& ans){
        if(root==NULL){
            //ans.push_back(path);
            return;
        }
        if(leaf(root)){
            if(path.length()!=0){
                path+="->";
            }
            path+=to_string(root->val);
            ans.push_back(path);
            return;
        }
        if(path.length()!=0){
            path+="->";
        }
        path+=to_string(root->val);
        findPath(root->left,path,ans);
        findPath(root->right,path,ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string path;
        findPath(root,path,ans);
        return ans;
    }
};
