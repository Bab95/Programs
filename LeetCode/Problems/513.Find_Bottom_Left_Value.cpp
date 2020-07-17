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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* ans = NULL;
        while(!q.empty()){
            int n = q.size();
            bool flag = false;
            for(int i=0;i<n;++i){
                TreeNode* current = q.front();
                q.pop();
                if(!flag){
                    ans = current;
                    flag = true;
                }
                if(current->left){
                    q.push(current->left);
                }
                if(current->right){
                    q.push(current->right);
                }
            }
        }
        if(ans!=NULL){
            return ans->val;
        }
        return -1;
    }
};
