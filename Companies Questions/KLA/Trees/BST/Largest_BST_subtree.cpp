 //Definition for a binary tree node.
 #include <bits/stdc++.h>
 using namespace std;
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

/*
Solution: start from the bottom if left_subtree is BST and right_subtree is BST
then check if they make BST with root if yes then update the max_size of BST
and return new BST

NEUTRAL VAL is {INT_MAX,INT_MIN,false,0};
*/
class Solution {
public:
    struct node{
        int mmax,mmin;
        bool isBst;
        int size;
        node(int mmin,int mmax,bool isBst,int size):mmin(mmin),mmax(mmax),isBst(isBst),size(size){}
    };
    struct node* findBst(TreeNode* root,int& ans){
        if(root==NULL){
            return new node(INT_MAX,INT_MIN,true,0);
        }
        node* left = findBst(root->left,ans);
        node* right = findBst(root->right,ans);
        if(left->isBst&&right->isBst){
            if(left->mmax<root->val&&right->mmin>root->val){
                ans = max(left->size+right->size+1,ans);
                int min_val = min(root->val,min(left->mmin,right->mmin));
                int max_val = max(root->val,max(left->mmax,right->mmax));
                return new node(min_val,max_val,true,left->size+right->size+1);
            }
        }
        return new node(INT_MAX,INT_MIN,false,0);
    }
    int largestBSTSubtree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int ans = -1;
        struct node* Node = findBst(root,ans);
        return  ans;
    }
};