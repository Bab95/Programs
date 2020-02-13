/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void Sum(TreeNode* root,int L,int R,int *sum){
        if(root==NULL){
            return;
        }
        if(root->val<L){
            Sum(root->right,L,R,sum);
        }else if(root->val>R){
            Sum(root->left,L,R,sum);
        }else if(root->val>=L&&root->val<=R){
            *sum = *sum+root->val;
            Sum(root->left,L,R,sum);
            Sum(root->right,L,R,sum);
        }
    }
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(root==NULL){
            return 0;
        }
        int result = 0;
        Sum(root,L,R,&result);
        return result;
    }
};
