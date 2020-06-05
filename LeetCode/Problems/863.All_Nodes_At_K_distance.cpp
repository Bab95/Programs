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
    void dfs(TreeNode* root,TreeNode* parent,unordered_map<TreeNode*,TreeNode*>& parents){
        if(root==NULL){
            return;
        }
        parents[root] = parent;
        dfs(root->left,root,parents);
        dfs(root->right,root,parents);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
       unordered_map<TreeNode*,TreeNode*> parents;
        dfs(root,NULL,parents);
        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited.insert(target);
        int level = 0;
        while(level!=k){
            int n = q.size();
            for(int i=0;i<n;++i){
                TreeNode* node = q.front();
                q.pop();
                if(node->left&&visited.find(node->left)==visited.end()){
                    q.push(node->left);
                    visited.insert(node->left);
                }
                if(node->right&&visited.find(node->right)==visited.end()){
                    q.push(node->right);
                    visited.insert(node->right);
                }
                if(parents[node]!=NULL&&visited.find(parents[node])==visited.end()){
                    q.push(parents[node]);
                    visited.insert(parents[node]);
                }
            }
            ++level;
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};
