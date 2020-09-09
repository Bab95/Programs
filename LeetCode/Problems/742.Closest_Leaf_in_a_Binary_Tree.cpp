/*
Given a binary tree where every node has a unique value, and a target key k, find the value of the nearest leaf node to target k in the tree.

Here, nearest to a leaf means the least number of edges travelled on the binary tree to reach any leaf of the tree. Also, a node is called a leaf if it has no children.

In the following examples, the input tree is represented in flattened form row by row. The actual root tree given will be a TreeNode object.


*/


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
    void dfs(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& mmap,int k,TreeNode*& req){
        if(root==NULL){
            return;
        }
        if(root->val==k){
            req = root;
        }
        if(root->left){
            mmap[root->left] = root;
        }
        if(root->right){
            mmap[root->right] = root;
        }
        dfs(root->left,mmap,k,req);
        dfs(root->right,mmap,k,req);
    }
    bool is_leaf(TreeNode* root){
        if(root==NULL){
            return false;
        }
        if(root->left==NULL&&root->right==NULL){
            return true;
        }
        return false;
    }
    int bfs(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& mmap){
        if(!root){
            cout<<"here";
            return -1;
        }
        queue<pair<int,TreeNode*>> q;
        q.push({0,root});
        pair<int,TreeNode*> ans;
        ans.first = INT_MAX;
        ans.second = NULL;
        unordered_set<TreeNode*> visited;
        while(!q.empty()){
            auto it = q.front();
            visited.insert(it.second);
            q.pop();
            if(is_leaf(it.second)){
                if(ans.first>it.first){
                    ans.first = it.first;
                    ans.second = it.second;
                }
            }else{
                if(it.second->left&&visited.find(it.second->left)==visited.end()){
                    q.push({it.first+1,it.second->left});
                }
                if(it.second->right&&visited.find(it.second->right)==visited.end()){
                    q.push({it.first+1,it.second->right});
                }
                if(mmap[it.second]&&visited.find(mmap[it.second])==visited.end()){
                    q.push({it.first+1,mmap[it.second]});
                }
            }
        }
        return ans.second->val;
    }
    int findClosestLeaf(TreeNode* root, int k) {
        unordered_map<TreeNode*,TreeNode*> mmap;
        TreeNode* req = NULL;
        dfs(root,mmap,k,req);
        cout<<req->val<<endl;
        return bfs(req,mmap);
    }
};
