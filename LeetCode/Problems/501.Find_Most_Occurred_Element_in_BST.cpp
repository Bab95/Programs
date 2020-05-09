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
    void inorder(TreeNode* root,TreeNode** currentNode,int& maxFreq,int& current,vector<int>& ans){
        if(root==NULL){
            return;
        }
        inorder(root->left,currentNode,maxFreq,current,ans);
        if((*currentNode)->val==root->val){
            current++;
        }else{
            current = 1;
        }
        if(current>maxFreq){
            ans.clear();
            maxFreq = current;
            ans.push_back(root->val);
        }else if(current==maxFreq){
            ans.push_back(root->val);
        }
        (*currentNode) = root;
        inorder(root->right,currentNode,maxFreq,current,ans);
    }
    vector<int> findMode(TreeNode* root) {
        int maxFreq = 0;
        int current = 0;
        TreeNode* currentNode = root;
        vector<int> ans;
        inorder(root,&currentNode,maxFreq,current,ans);
        return ans;
    }
};
