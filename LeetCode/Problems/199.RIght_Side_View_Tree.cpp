/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <queue>
class Solution {
public:
    void rightview(TreeNode* root,vector<int>& result){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* current = q.front();
            result.push_back(current->val);
            int n = q.size();
            for(int i=0;i<n;i++){
                current = q.front();
                q.pop();
                if(current->right){
                    q.push(current->right);
                }
                if(current->left){
                    q.push(current->left);
                }
            }
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(root==NULL){
            return result;
        }
        rightview(root,result);
        return result;
    }
};
