/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int search(vector<int>& inorder,int root,int start,int end){
        for(int i=start;i<=end;++i){
            if(root==inorder[i]){
                return i;
            }
        }
        return -1;
    }
    TreeNode* constructTree(vector<int>& preorder,vector<int>& inorder,int& preindex,int instart,int inend){
        if(preindex>preorder.size()-1||instart>inend){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[preindex]);
        preindex++;
        int inIndex = search(inorder,root->val,instart,inend);
        if(inIndex!=instart){
            root->left = constructTree(preorder,inorder,preindex,instart,inIndex-1);
        }
        if(inIndex!=inend){
            root->right = constructTree(preorder,inorder,preindex,inIndex+1,inend);
        }
        return root;

    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder;
        inorder.reserve(preorder.size());
        inorder.insert(inorder.end(),preorder.begin(),preorder.end());
        sort(inorder.begin(),inorder.end());
        int preIndex = 0;
        return constructTree(preorder,inorder,preIndex,0,inorder.size()-1);
    }
};
