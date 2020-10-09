/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void find_values(TreeNode* root,TreeNode* &prev,TreeNode* &first,TreeNode* &second){
    if(root==NULL){
        return;
    }
    find_values(root->left,prev,first,second);
    if(prev!=NULL&&first==NULL&&prev->val>root->val){
        first = prev;
    }
    if(prev!=NULL&&first!=NULL&&root->val<prev->val){
        second = root;
    }
    prev = root;
    find_values(root->right,prev,first,second);
}
void inorder(TreeNode* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
vector<int> Solution::recoverTree(TreeNode* root) {
    //inorder(root);
    TreeNode* prev = NULL;
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    find_values(root,prev,first,second);
    if(first->val>second->val){
        swap(first,second);
    }
    return {first->val,second->val};
}
