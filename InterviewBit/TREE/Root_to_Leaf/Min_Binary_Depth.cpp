/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool leaf(TreeNode* root){
    if(root==NULL){
        return false;
    }
    if(root->left==NULL&&root->right==NULL){
        return true;
    }
    return false;
}
void find_min_depth(TreeNode* root,int& length,int current){
    if(root==NULL){
        return;
    }
    if(leaf(root)){
        length = min(current+1,length);
        return;
    }
    find_min_depth(root->left,length,current+1);
    find_min_depth(root->right,length,current+1);
}
int Solution::minDepth(TreeNode* root) {
    int length = INT_MAX;
    find_min_depth(root,length,0);
    return length;
}
