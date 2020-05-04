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
    int findDepth(TreeNode*root,TreeNode** parent,int x,int d){
        if(root==NULL){
            return INT_MAX;
        }
        if(root->left&&root->left->val==x){
            *parent = root;
            return d+1;
        }
        else if(root->right&&root->right->val==x){
            *parent = root;
            return d+1;
        }
        int left = findDepth(root->left,parent,x,d+1);
        int right = findDepth(root->right,parent,x,d+1);
        return (left==INT_MAX)?right:left;
    }
    bool isCousins(TreeNode* root, int x, int y) {
        TreeNode* xparent = NULL;
        TreeNode* yparent = NULL;
        int dx = 0,dy = 0;
        dx = findDepth(root,&xparent,x,dx);
        dy = findDepth(root,&yparent,y,dy);
        if(dx==dy){
            if(xparent==yparent){
                return false;
            }else if(xparent!=yparent){
                return true;
            }
        }
        return false;

    }
};
