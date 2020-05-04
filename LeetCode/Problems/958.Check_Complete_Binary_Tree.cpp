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
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return max(height(root->left),height(root->right))+1;
    }
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool children_allowed = true;

        while(!q.empty()){
            TreeNode* t = q.front();
            q.pop();
            if(t->left){
                if(!children_allowed){
                    return false;
                }else{
                    q.push(t->left);
                    if(t->right){
                        q.push(t->right);
                    }else{
                        children_allowed = false;
                    }
                }
            }else if(t->right){
                return false;
            }else{
                children_allowed = false;
            }
        }
        return true;
    }
};
