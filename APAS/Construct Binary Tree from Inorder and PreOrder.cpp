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
    int searchIndex(vector<int>& inorder,int instart,int inend,int target){
        for(int i=instart;i<=inend;i++){
            if(inorder[i]==target){
                return i;
            }
        }
        return -1;
    }
    TreeNode* buildUtil(vector<int>& preorder,vector<int>& inorder,int inStart,int inEnd,int *preindex){
        if(inStart>inEnd){
            return NULL;
        }
        int index = searchIndex(inorder,inStart,inEnd,preorder[*preindex]);
        TreeNode* root = new TreeNode(preorder[*preindex]);
        *preindex = *preindex+1;
        root->left = buildUtil(preorder,inorder,inStart,index-1,preindex);
        root->right = buildUtil(preorder,inorder,index+1,inEnd,preindex);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int inStart = 0;
        int inEnd = inorder.size()-1;
        int preIndex = 0;
        return buildUtil(preorder,inorder,inStart,inEnd,&preIndex);
    }
};
