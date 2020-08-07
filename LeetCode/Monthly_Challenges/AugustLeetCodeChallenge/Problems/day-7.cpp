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
    struct compare {
        size_t operator() (const pair<int, TreeNode*>& p,const pair<int, TreeNode*>& q) const
        {
            if(p.second->val<q.second->val){
                return true;
            }
            return  false;
        }
    };
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<int> > mmap;
        set<pair<int,TreeNode*>, compare > q,r;
        q.insert({0,root});
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;++i){
                pair<int,TreeNode*> p = *q.begin();
                q.erase(q.begin());
                mmap[p.first].push_back(p.second->val);
                if(p.second->left){
                    r.insert({p.first-1,p.second->left});
                }
                if(p.second->right){
                    r.insert({p.first+1,p.second->right});
                }
            }
            swap(q,r);
        }
        vector<vector<int> > ans(mmap.size(),vector<int>());
        int k = 0;
        for(auto &it : mmap){
            ans[k++] = it.second;
        }
        return ans;
    }
};
