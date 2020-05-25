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
    int ans = 0;
    bool ispalindromic(vector<int>& path){
        unordered_map<int,int> mmap;
        for(int i=0;i<path.size();++i){
            mmap[path[i]]++;
        }
        bool odd = (path.size()%2==0)?false:true;
        for(auto it=mmap.begin();it!=mmap.end();++it){
            if((it->second)%2==1&&odd){
                odd = false;
                continue;
            }else if(it->second%2==1&&!odd){
                return false;
            }
        }
        return true;
    }
    bool leaf(TreeNode* root){
        if(root==NULL){
            return false;
        }
        if(root->left==NULL&&root->right==NULL){
            return true;
        }
        return false;
    }
    void findPath(TreeNode* root,vector<int>& path){
        if(root==NULL){
            return;
        }
        if(leaf(root)){
            path.push_back(root->val);
            if(ispalindromic(path)){
                ans++;
            }
            path.pop_back();
        }
        path.push_back(root->val);
        findPath(root->left,path);
        findPath(root->right,path);
        path.pop_back();
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> path;
        if(root==NULL){
            return 0;
        }
        if(leaf(root)){
            return 1;
        }
        findPath(root,path);
        return ans;
    }
};
