class Solution {
public:
    void inorder(TreeNode* root,TreeNode* &prev,TreeNode* &a,TreeNode* &b){
        if(root==NULL){
            return;
        }
        inorder(root->left,prev,a,b);
        if(prev&&a==NULL&&prev->val>root->val){
            a = prev;
        }
        if(prev&&a!=NULL&&prev->val>root->val){
            b = root;
        }
        prev = root;
        inorder(root->right,prev,a,b);
    }
    void recoverTree(TreeNode* root) {
        TreeNode* a = NULL;
        TreeNode* b = NULL;
        TreeNode* prev = NULL;
        inorder(root,prev,a,b);
        if(a!=NULL){
            int tmp = a->val;
            a->val = b->val;
            b->val = tmp;
            cout<<"hello"<<a->val<<" "<<b->val<<endl;
        }
    }
};
