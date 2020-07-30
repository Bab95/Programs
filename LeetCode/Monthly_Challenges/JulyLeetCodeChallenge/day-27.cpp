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
    int find_index(vector<int>& inorder,int key,int low,int high){
        for(int i=low;i<=high;++i){
            if(inorder[i]==key){
                return i;
            }
        }
        return -1;
    }
    TreeNode* build(vector<int>& inorder,vector<int>& postorder,int& index,int low,int high){
        if(index<0){
            return NULL;
        }
        if(low==high){
            return new TreeNode(postorder[index--]);
        }
        TreeNode* root = new TreeNode(postorder[index]);
        int in_index = find_index(inorder,postorder[index],low,high);
        index--;
        if(in_index<high)
            root->right = build(inorder,postorder,index,in_index+1,high);
        if(in_index>low)
            root->left = build(inorder,postorder,index,low,in_index-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int index = postorder.size()-1;
        TreeNode* root = build(inorder,postorder,index,0,inorder.size()-1);
        return root;

    }
};
