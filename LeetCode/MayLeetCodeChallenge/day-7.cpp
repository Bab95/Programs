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
    int findDepth(TreeNode* root,int x,TreeNode** parent,int d){
        if(root==NULL){
            return INT_MAX;
        }
        if(root->left&&root->left->val==x){
            *parent = root;
            return d+1;
        }
        if(root->right&&root->right->val==x){
            *parent = root;
            return d+1;
        }
        int ld = findDepth(root->left,x,parent,d+1);
        int rd = findDepth(root->right,x,parent,d+1);
        return ld!=INT_MAX?ld:rd;
    }
    bool isCousins(TreeNode* root, int x, int y) {
        TreeNode* xparent = NULL;
        TreeNode* yparent = NULL;
        int dx = findDepth(root,x,&xparent,0);
        int dy = findDepth(root,y,&yparent,0);
        if(xparent==NULL||yparent==NULL){
            return false;
        }
        if(dx==dy){
            if(xparent!=yparent){
                return true;
            }
        }
        return false;
    }
};
