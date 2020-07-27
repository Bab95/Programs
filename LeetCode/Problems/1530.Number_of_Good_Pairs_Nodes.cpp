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
    bool is_leaf(TreeNode* node){
        if(node!=NULL){
            if(node->left==NULL&&node->right==NULL){
                return true;
            }
        }
        return false;
    }
    void store(TreeNode* root,unordered_set<TreeNode*>& leafs,unordered_map<TreeNode*,TreeNode*>& parents){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* current = q.front();
            if(is_leaf(current)){
                leafs.insert(current);
            }
            q.pop();
            if(current->left){
                q.push(current->left);
                parents[current->left] = current;
            }
            if(current->right){
                q.push(current->right);
                parents[current->right] = current;
            }
        }
    }
    int bfs(TreeNode* root,unordered_set<TreeNode*>& leafs,unordered_map<TreeNode*,TreeNode*>& parents,int dist){
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        unordered_set<TreeNode*> visited,nodes;
        visited.insert(root);
        while(!q.empty()){
            level++;
            if(level>dist+1){
                break;
            }
            int n = q.size();
            for(int i=0;i<n;++i){
                TreeNode* current = q.front();
                q.pop();
                if(current->left&&visited.count(current->left)==0){
                    q.push(current->left);
                    visited.insert(current->left);
                }
                if(current->right&&visited.count(current->right)==0){
                    q.push(current->right);
                    visited.insert(current->right);
                }
                if(parents[current]&&visited.count(parents[current])==0){
                    q.push(parents[current]);
                    visited.insert(parents[current]);
                }
                if(is_leaf(current)&&current!=root){
                    nodes.insert(current);
                    //cout<<"jhgkh";
                }
            }
        }
        /*for(auto it:nodes){
            cout<<it->val<<" ";
        }
        cout<<endl;*/
        //cout<<nodes.size()<<endl;
        return nodes.size();
    }
    int countPairs(TreeNode* root, int distance) {
        unordered_set<TreeNode*> leafs;
        unordered_map<TreeNode*,TreeNode*> parents;
        store(root,leafs,parents);
        if(leafs.size()<2){
            return 0;
        }
        int ans = 0;
        cout<<leafs.size()<<endl;
        for(auto it=leafs.begin();it!=leafs.end();++it){
            TreeNode* current = *it;
            ans += bfs(current,leafs,parents,distance);
        }
        return ans/2;
    }
};
