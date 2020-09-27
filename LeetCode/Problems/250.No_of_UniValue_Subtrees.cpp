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
    pair<bool,int> find_subtrees(TreeNode* root){
        if(root==NULL){
            return {true,0};
        }
        if(root->left==NULL&&root->right==NULL){
            return {true,1};
        }
        pair<bool,int> left = find_subtrees(root->left);
        pair<bool,int> right = find_subtrees(root->right);
        if(left.first==true&&right.first==true){
            if((root->left&&root->right==NULL&&root->left->val==root->val)||(root->right&&root->left==NULL&&root->right->val==root->val)){
                return {true,left.second+right.second+1};
            }else if(root->left&&root->right&&root->left->val==root->right->val&&root->val==root->left->val){
                return {true,left.second+right.second+1};
            }else{
                return {false,left.second+right.second};
            }
        }else{
            return {false,left.second+right.second};
        }
        return {false,0};
    }
    int countUnivalSubtrees(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        pair<bool,int> ans = find_subtrees(root);
        return ans.second;

    }
};
