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
    void dfs(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent,queue<TreeNode*>& q){
        if(root==NULL){
            return;
        }
        if(root->left==NULL&&root->right==NULL){
            q.push(root);
        }
        if(root->left){
            parent[root->left] = root;
            dfs(root->left,parent,q);
        }
        if(root->right){
            parent[root->right] = root;
            dfs(root->right,parent,q);
        }
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        unordered_map<TreeNode*,TreeNode*> parent;
        queue<TreeNode*> q;
        dfs(root,parent,q);
        vector<vector<int> > ans;
        while(!q.empty()){
            int n = q.size();
            vector<int> current_leaves;
            for(int i=0;i<n;++i){
                TreeNode* current = q.front();
                current_leaves.push_back(current->val);
                q.pop();
                if(parent.find(current)!=parent.end()){
                    if(parent[current]->left==current){
                        parent[current]->left = NULL;
                    }else if(parent[current]->right==current){
                        parent[current]->right = NULL;
                    }
                    if(parent[current]->left==NULL&&parent[current]->right==NULL){
                        q.push(parent[current]);
                    }
                }
            }
            ans.push_back(current_leaves);
        }
        //ans.push_back({root->val});
        return ans;
    }
};
