/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void dfs(Node* root,unordered_map<Node*,Node*>& parent){
        if(root==NULL){
            return;
        }
        for(int i=0;i<root->children.size();++i){
            if(parent.find(root->children[i])==parent.end()){
                parent[root->children[i]] = root;
                dfs(root->children[i],parent);
            }
        }
    }
    pair<Node*,int> bfs(Node* root,unordered_map<Node*,Node*>& dp){
        queue<pair<Node*,int> > q;
        q.push({root,0});
        unordered_set<Node*> visited;
        pair<Node*,int> ans = {NULL,-1};
        while(!q.empty()){
            auto it = q.front();
            visited.insert(it.first);
            if(it.second>ans.second){
                ans = it;
            }
            q.pop();
            for(int i=0;i<it.first->children.size();++i){
                if(visited.find(it.first->children[i])==visited.end()){
                    q.push({it.first->children[i],it.second+1});
                }
            }
            if(dp.find(it.first)==dp.end()){
                continue;
            }
            if(visited.find(dp[it.first])==visited.end()){
                q.push({dp[it.first],it.second+1});
            }
        }
        return ans;
    }
    int diameter(Node* root) {
        unordered_map<Node*,Node*> dp;
        dfs(root,dp);
        pair<Node*,int> far = bfs(root,dp);
        cout<<far.first->val<<" "<<far.second<<endl;
        far = bfs(far.first,dp);
        return far.second;
    }
};
