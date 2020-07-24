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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        vector<vector<int> > ans;
        while(!q.empty()){
            int n = q.size();
            vector<int> tmp;
            for(int i=0;i<n;++i){
                TreeNode* current = q.front();
                q.pop();
                if(current->left){
                    q.push(current->left);
                }
                if(current->right){
                    q.push(current->right);
                }
                tmp.push_back(current->val);
            }
            if(level%2==1){
                reverse(tmp.begin(),tmp.end());
            }
            ans.push_back(tmp);
            level++;
        }
        return ans;
    }
};
