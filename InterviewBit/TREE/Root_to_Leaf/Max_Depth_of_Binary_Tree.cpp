/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int find_max_Depth(TreeNode* root,int& length){
    if(root==NULL){
        return 0;
    }
    int left = find_max_Depth(root->left,length);
    int right = find_max_Depth(root->right,length);
    length = max(left+1,max(right+1,length));
    return max(left,right)+1;
}
int Solution::maxDepth(TreeNode* A) {
    int length = 0;
    find_max_Depth(A,length);
    return length;
}
