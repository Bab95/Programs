int nth_Node(TreeNode* root,int& current,int n){
  if(root==NULL){
    return;
  }
  nth_Node(root->left,current,n);
  current++;
  if(current==n){
    return root->val;
  }
  nth_Node(root->right,current,n);
}
