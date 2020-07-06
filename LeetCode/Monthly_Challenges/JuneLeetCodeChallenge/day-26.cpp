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
    void number_construct(TreeNode* root,int number,int *result){
        if(root==NULL){
            return;
        }
        if(root->left==NULL&&root->right==NULL){
            number = number*10+root->data;
            *result = *result+number;
        }
        number_construct(root->left,number*10+root->data,result);
        *result = *result+number;
        number_construct(root->right,number*10+root->data,result);
    }
    int sumNumbers(TreeNode* root) {
        int result = 0;
        number_construct(root,0,&result);
        return result;
    }
};
