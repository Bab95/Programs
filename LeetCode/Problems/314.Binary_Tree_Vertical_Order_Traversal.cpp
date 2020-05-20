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
    static bool compare(const pair<int,pair<int,int> >& p1,const pair<int,pair<int,int> >& p2){
        //first is horizonal distance second is level and third is val....
        if(p1.second.first==p2.second.first){
            if(p1.first<p2.first){
                return true;
            }
        }
        //if level equal then left most wins
        return false;
    }
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        map<int,vector<pair<int,pair<int,int> > > > mmap;
        queue<pair<int,pair<TreeNode*,int> > > q;
        q.push(make_pair(0,make_pair(root,0)));
        while(!q.empty()){
            pair<int,pair<TreeNode*,int> > p = q.front();
            q.pop();
            mmap[p.first].push_back(make_pair(p.first,make_pair(p.second.second,p.second.first->val)));
            if(p.second.first->left){
                pair<int,pair<TreeNode*,int> > left = make_pair(p.first-1,make_pair(p.second.first->left,p.second.second+1));
                q.push(left);
            }
            if(p.second.first->right){
                pair<int,pair<TreeNode*,int> > right = make_pair(p.first+1,make_pair(p.second.first->right,p.second.second+1));
                q.push(right);
            }
        }
        vector<vector<int> > ans;
        for(auto it=mmap.begin();it!=mmap.end();++it){
            sort(it->second.begin(),it->second.end(),compare);
        }
        for(auto it=mmap.begin();it!=mmap.end();++it){
            vector<int> res;
            res.reserve(it->second.size());
            for(auto i=it->second.begin();i!=it->second.end();++i){
                res.push_back(i->second.second);
            }
            ans.push_back(res);
        }
        return ans;
    }
};
