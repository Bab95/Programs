/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool leaf(TreeNode* A){
    if(A==NULL){
        return false;
    }
    if(A->left==NULL&&A->right==NULL){
        return true;
    }
    return false;
}
int Solution::hasPathSum(TreeNode* A, int B) {
    if(A==NULL){
        return 0;
    }
    if(leaf(A)&&B-A->val==0){
        return 1;
    }
    int left = hasPathSum(A->left,B-A->val);
    int right = hasPathSum(A->right,B-A->val);
    return left|right;
}
