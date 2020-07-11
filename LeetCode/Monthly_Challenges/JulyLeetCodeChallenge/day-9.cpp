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
typedef unsigned long long int ulli;
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        queue<pair<TreeNode*,ulli> >  q;
        q.push(make_pair(root,0));
        ulli ans = 0;
        while(!q.empty()){
            int n = q.size();
            ulli left_most = q.front().second;
            ulli right_most = 0;
            for(int i=0;i<n;++i){
                right_most = q.front().second;
                pair<TreeNode*,ulli> p = q.front();
                q.pop();
                if(p.first->left){
                    q.push(make_pair(p.first->left,2*p.second+1));
                }
                if(p.first->right){
                    q.push(make_pair(p.first->right,2*p.second+2));
                }
            }
            ulli current = right_most-left_most+1;
            ans = max(ans,current);
        }
        return ans;
    }
};
