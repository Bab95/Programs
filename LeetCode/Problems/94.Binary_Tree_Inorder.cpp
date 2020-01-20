/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <stack>
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* current = root;
        stack<TreeNode*> s;
        vector<int> result;
        while(!s.empty()||current!=NULL){
            while(current!=NULL){
                s.push(current);
                current = current->left;
            }
            current = s.top();
            s.pop();
            result.push_back(current->val);
            current = current->right;
        }
        return result;
    }
};
