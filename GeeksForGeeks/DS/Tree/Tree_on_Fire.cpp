#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};
void dfs(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent){
    if(root==NULL){
        return;
    }
    if(root->left){
        parent[root->left] = root;
        dfs(root->left,parent);
    }
    if(root->right){
        parent[root->right] = root;
        dfs(root->right,parent);
    }

}
int bfs(TreeNode* onFire,unordered_map<TreeNode*,TreeNode*>& parent,TreeNode* root){
    queue<pair<TreeNode*,int> > q;
    q.push({onFire,0});
    unordered_set<TreeNode*> visited;
    int ans = -1;
    while(!q.empty()){
        pair<TreeNode*,int> current = q.front();
        visited.insert(current.first);
        ans = max(ans,current.second);
        q.pop();
        if(current.first->left&&visited.find(current.first->left)==visited.end()){
            q.push({current.first->left,current.second+1});
        }
        if(current.first->right&&visited.find(current.first->right)==visited.end()){
            q.push({current.first->right,current.second+1});
        }
        if(parent.find(current.first)==parent.end()){
            if(visited.find(parent[current.first])==visited.end()){
                q.push({parent[current.first],current.second+1});
            }
        }
    }
    return ans;
}
int time_to_burn(TreeNode* root,TreeNode* onFire){
    unordered_map<TreeNode*,TreeNode*> parent;
    dfs(root,parent);
    int time = bfs(onFire,parent,root);
}
int main(){
    TreeNode* root;
    TreeNode* onFire;
    int t = time_to_burn(root,onFire);
    cout<<t<<endl;
}