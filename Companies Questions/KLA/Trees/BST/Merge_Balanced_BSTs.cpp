#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <queue>
/*
Solution:
Convert 2 Bsts to DLL's
Merge two Sorted DLL's
Construct BST from DLL

*/
using namespace std;
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 void Convert2DLL(TreeNode* root,TreeNode* &prev,TreeNode* &head){
     if(root==NULL){
         return;
     }
     Convert2DLL(root->left,prev,head);
     if(prev==NULL){
         prev = root;
         head = root;
     }else{
         prev->right = root;
         root->left = prev;
         prev = root;
     }
     Convert2DLL(root->right,prev,head);
 }
 TreeNode* Merge2DLLs(TreeNode* root1,TreeNode* root2){
     if(root1==NULL){
         return root2;
     }
     if(root2==NULL){
         return root1;
     }
     if(root1->val<root2->val){
        root1->right = Merge2DLLs(root1->right,root2);
        root1->right->left = root1;
        root1->left = NULL;
        return root1;
     }else{
         root2->right = Merge2DLLs(root1,root2->right);
         root2->right->left = root2;
         root2->left = NULL;
         return root2;
     }
     return NULL;
 }
 int countNodes(TreeNode* root){
     int res = 0;
     while(root){
         res++;
         root = root->right;
     }
     return res;
 }
 TreeNode* _Convert2BST(TreeNode* &head,int count){
     if(count<=0){
         return NULL;
     }
     TreeNode* left = _Convert2BST(head,count/2);
     TreeNode* root = head;
     root->left = left;
     head = head->right;
     root->right = _Convert2BST(head,count-count/2-1);
     return root;
 }
 TreeNode* Convert2BST(TreeNode* head){
     int count = countNodes(head);
     return _Convert2BST(head,count);
 }
 TreeNode* MergeTwoBSTs(TreeNode* root1,TreeNode* root2){
     TreeNode* head1 = NULL;
     TreeNode* head2 = NULL;
     TreeNode* prev1 = NULL;
     TreeNode* prev2 = NULL;
     Convert2DLL(root1,prev1,head1);
     Convert2DLL(root2,prev2,head2);
     TreeNode* Head = Merge2DLLs(head1,head2);
     TreeNode* Root = Convert2BST(Head);
     return Root;
 }
 void inorder(TreeNode* root){
     if(root==NULL){
         return;
     }
     inorder(root->left);
     cout<<root->val<<" ";
     inorder(root->right);
 }
int main(){
    TreeNode* root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(13);
    inorder(root1);
    cout<<endl;

    TreeNode* root2 = new TreeNode(4);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(6);
    root2->left->left = new TreeNode(1);
    root2->left->right = new TreeNode(3);
    root2->right->left = new TreeNode(5);
    root2->right->right = new TreeNode(7);
    inorder(root2);
    cout<<endl;

    TreeNode* _merged = MergeTwoBSTs(root1,root2);
    inorder(_merged);
    cout<<endl;

    return 0;
}