
  //Definition for a binary tree node.
  struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
/*
Solution : do inorder traversal keeping the track of previous node.
Suppose we are moving in a sorted array and two values are swapped then
definitely first will be bigger value and second will be smaller value
If inorder was : 1 2 [6] 4 5 [3] 7
First node will occur will be larger than its previous.
*/
using namespace std;
#define NULL 0
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