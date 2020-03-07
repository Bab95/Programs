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
    int searchIndex(int start,int end,vector<int>& inorder,int target){
        for(int i=start;i<=end;i++){
            if(inorder[i]==target){
                return i;
            }
        }
        return -1;
    }
    TreeNode* buildTreeUtil(vector<int>& inorder,vector<int>& postorder,int instart,int inend,int *postindex){
        if(instart>inend){
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder[*postindex]);
        int index = searchIndex(instart,inend,inorder,postorder[*postindex]);
        *postindex = *postindex-1;
        root->right = buildTreeUtil(inorder,postorder,index+1,inend,postindex);
        root->left = buildTreeUtil(inorder,postorder,instart,index-1,postindex);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postindex = postorder.size()-1;
        return buildTreeUtil(inorder,postorder,0,inorder.size()-1,&postindex);
    }
};
