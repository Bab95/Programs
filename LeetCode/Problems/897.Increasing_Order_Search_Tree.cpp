/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root,vector<TreeNode*>& arr){
        if(root==NULL){
            return;
        }
        inorder(root->left,arr);
        arr.push_back(root);
        inorder(root->right,arr);
    }
    TreeNode* increasingBST(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }
        vector<TreeNode*> arr;
        inorder(root,arr);
        for(int i=1;i<arr.size();++i){
            arr[i-1]->left = NULL;
            arr[i-1]->right = arr[i];
        }
        return arr[0];
    }
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution2 {
public:
    void inorder(TreeNode* root,TreeNode** prev,TreeNode** h_ref){
        if(root==NULL){
            return;
        }
        inorder(root->left,prev,h_ref);
        if(*h_ref==NULL){
            *h_ref = root;
            *prev = root;
        }else{
            (*prev)->right = root;
            (*prev)->left = NULL;
            (*prev) = root;
        }
        inorder(root->right,prev,h_ref);
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* prev = NULL;
        TreeNode* h_ref = NULL;
        inorder(root,&prev,&h_ref);
        return h_ref;
    }
};
