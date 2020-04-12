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
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        queue<TreeNode*> q;
        vector<int> ans;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            int max_val = INT_MIN;
            for(int i=0;i<n;++i){
                max_val = max(max_val,q.front()->val);
                if(q.front()->left){
                    q.push(q.front()->left);
                }
                if(q.front()->right){
                    q.push(q.front()->right);
                }
                q.pop();
            }
            ans.push_back(max_val);
        }
        return ans;
    }
};