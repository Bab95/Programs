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
    int maxLevelSum(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        queue<TreeNode*> q;
        pair<int,int> ans;
        ans = make_pair(root->val,1);
        q.push(root);
        int level = 1;
        while(!q.empty()){
            int n = q.size();
            int current_sum = 0;
            for(int i=0;i<n;++i){
                TreeNode* current = q.front();
                q.pop();
                current_sum+=current->val;
                if(current->left){
                    q.push(current->left);
                }
                if(current->right){
                    q.push(current->right);
                }
            }
            if(current_sum>ans.first){
                ans.first = current_sum;
                ans.second = level;
            }
            level++;
        }
        return ans.second;
    }
};
