/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<deque>
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > result;
        if(root==NULL){
            return result;
        }
        deque<TreeNode*> dq;
        dq.push_back(root);
        int level = 0;
        while(!dq.empty()){
            int n = dq.size();
            vector<int> tmp;
            if(level%2==0){
                for(int i=0;i<n;i++){
                    TreeNode* current = dq.front();
                    dq.pop_front();
                    if(current->left){
                        dq.push_back(current->left);
                    }
                    if(current->right){
                        dq.push_back(current->right);
                    }
                    tmp.push_back(current->val);
                }
                level = level + 1;
            }else{
                for(int i=0;i<n;i++){
                    TreeNode* current = dq.back();
                    dq.pop_back();
                    if(current->right){
                        dq.push_front(current->right);
                    }
                    if(current->left){
                        dq.push_front(current->left);
                    }
                    tmp.push_back(current->val);
                }
                level = level + 1;
            }
            if(tmp.size()!=0){
                result.push_back(tmp);
            }
        }
        return result;
    }
};
