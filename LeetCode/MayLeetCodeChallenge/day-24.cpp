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
    int search(vector<int>& inorder,int key){
        for(int i=0;i<inorder.size();++i){
            if(inorder[i]==key){
                return i;
            }
        }
        return -1;
    }
    TreeNode* construct(vector<int>& inorder,vector<int>& preorder,int& preindex,int instart,int inend){
        if(inend<instart){
            return NULL;
        }
        //if(preindex==preorder.size()){
          //  return NULL;
        //}
        TreeNode* root = new TreeNode(preorder[preindex++]);
        int inindex = search(inorder,root->val);
        if(inindex>0){
            root->left = construct(inorder,preorder,preindex,instart,inindex-1);
        }
        if(inindex<inend){
            root->right = construct(inorder,preorder,preindex,inindex+1,inend);
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder;
        inorder.reserve(preorder.size());
        inorder.insert(inorder.begin(),preorder.begin(),preorder.end());
        sort(inorder.begin(),inorder.end());
        int index = 0;
        TreeNode* root = construct(inorder,preorder,index,0,inorder.size()-1);
        return root;
    }
};
