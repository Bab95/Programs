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
    bool ans = false;
    bool is_subtree(TreeNode* s,TreeNode* t){
        if(s==NULL&&t==NULL){
            return true;
        }
        if(s==NULL||t==NULL){
            return false;
        }
        if(s->val==t->val){
            bool left = is_subtree(s->left,t->left);
            bool right = is_subtree(s->right,t->right);
            return left&&right;
        }
        return false;
    }
    void preorder(TreeNode* r1,TreeNode*r2){
        if(r1==NULL){
            return;
        }
        if(r1->val==r2->val){
            ans = ans || is_subtree(r1,r2);
            if(ans==true){
                return;
            }
        }
        preorder(r1->left,r2);
        preorder(r1->right,r2);
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        preorder(s,t);
        return ans;
    }
};
