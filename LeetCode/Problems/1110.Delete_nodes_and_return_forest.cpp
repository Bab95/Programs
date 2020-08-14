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
    void create_forest(TreeNode* root/*,unordered_map<TreeNode*,TreeNode*>& parent*/,vector<TreeNode*>& forest,unordered_set<int>& to_delete,unordered_set<TreeNode*>& deleted_nodes){
        if(root==NULL){
            return;
        }
        if(to_delete.find(root->val)!=to_delete.end()){
            deleted_nodes.insert(root);
            if(root->left){
                forest.push_back(root->left);
            }
            if(root->right){
                forest.push_back(root->right);
            }
        }
        create_forest(root->left,forest,to_delete,deleted_nodes);
        create_forest(root->right,forest,to_delete,deleted_nodes);
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_map<TreeNode*,TreeNode*> parent;
        parent[root] = NULL;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<q.size();++i){
                TreeNode* current = q.front();
                q.pop();
                if(current->left){
                    parent[current->left] = current;
                    q.push(current->left);
                }
                if(current->right){
                    parent[current->right] = current;
                    q.push(current->right);
                }
            }
        }
        vector<TreeNode*> forest;
        forest.push_back(root);
        unordered_set<int> _to_delete(to_delete.begin(),to_delete.end());
        unordered_set<TreeNode*> deleted_nodes;
        create_forest(root,forest,_to_delete,deleted_nodes);
        for(auto it=forest.begin();it!=forest.end();++it){
            TreeNode* myparent = parent[*it];
            //releasing me from my parent....
            if(myparent!=NULL){
                if(myparent->left==*it){
                    myparent->left = NULL;
                }else{
                    myparent->right = NULL;
                }
                //releasing branch from my parent...
                TreeNode* grand_parent = parent[myparent];
                if(grand_parent!=NULL){
                    if(grand_parent->left==myparent){
                        grand_parent->left = NULL;
                    }else{
                        grand_parent->right = NULL;
                    }
                }
            }
            if(deleted_nodes.count(*it)!=0){
                forest.erase(it);
            }
        }
        return forest;
    }
};
