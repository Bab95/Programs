/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
test-cases
[0,8,1,null,null,3,2,null,4,5,null,null,7,6]
[0,5,1,9,null,2,null,null,null,null,3,4,8,6,null,null,null,7]
*/
class Solution {
public:
    static bool mycomparator(const pair<int,int>& a,const pair<int,int>& b){
        if(a.first==b.first){
            return (a.second<b.second);
        }
        return (a.first<b.first);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int> > > mmap;
        queue<pair<int,pair<int,TreeNode*> > > q;
        pair<int,pair<int,TreeNode*> > p;
        p.first = 0;
        p.second.first = 0;
        p.second.second = root;
        q.push(p);
        while(!q.empty()){
            p = q.front();
            q.pop();
            pair<int,int> t;
            t.first = p.second.first;
            t.second = p.second.second->val;
            mmap[p.first].push_back(t);
            if(p.second.second->right){
                pair<int,pair<int,TreeNode*> > tmp;
                tmp.first = p.first + 1; // Horizontal distance....
                tmp.second.second = p.second.second->right;
                tmp.second.first = p.second.first + 1; //Level....
                q.push(tmp);
            }
            if(p.second.second->left){
                pair<int,pair<int,TreeNode*> > tmp;
                tmp.first = p.first - 1; // Horizontal distance....
                tmp.second.second = p.second.second->left;
                tmp.second.first = p.second.first + 1; //Level....
                q.push(tmp);
            }
            
        }
        vector<vector<int> > result;
        for(auto it=mmap.begin();it!=mmap.end();++it){
           sort(it->second.begin(),it->second.end(),mycomparator);
        }
        for(auto it=mmap.begin();it!=mmap.end();++it){
            vector<int> res;
            for(auto itr=it->second.begin();itr!=it->second.end();++itr){
                res.push_back(itr->second);
            }
            result.push_back(res);
        }
        return result;
    }
};