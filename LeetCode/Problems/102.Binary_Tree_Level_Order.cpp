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
    vector<vector<int>> levelOrder(TreeNode* root){
        vector<vector<int> > result;
        if(root==NULL){
            return result;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> tmp;
            for(int i=0;i<n;i++){
                TreeNode* current = q.front();
                q.pop();
                tmp.push_back(current->val);
                if(current->left){
                    q.push(current->left);
                }
                if(current->right){
                    q.push(current->right);
                }
            }
            if(tmp.size()!=0){
                result.push_back(tmp);
            }
        }
        return result;
    }
};
