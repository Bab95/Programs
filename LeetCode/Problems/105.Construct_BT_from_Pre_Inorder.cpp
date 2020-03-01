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
    int search(int val,vector<int>& inorder,int start,int end){
        for(int i=start;i<=end;i++){
            if(inorder[i]==val){
                return i;
            }
        }
        return -1;
    }
    TreeNode* buildUtil(vector<int>& preorder,vector<int>& inorder,int start,int end,int n,int* preindex){
        if(*preindex>n||start>end){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[*preindex]);
        *preindex = *preindex + 1;
        if(start==end){
            return root;
        }
        int inINdex = search(root->val,inorder,start,end);
        if(inINdex>0){
            root->left = buildUtil(preorder,inorder,start,inINdex-1,n,preindex);
        }
        if(inINdex<n){
            root->right = buildUtil(preorder,inorder,inINdex+1,end,n,preindex);
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0){
            return NULL;
        }
        if(preorder.size()==1){
            TreeNode* root = new TreeNode(preorder[0]);
            return root;
        }
        int preindex = 0;
        return buildUtil(preorder,inorder,0,inorder.size()-1,inorder.size()-1,&preindex);
    }
};
