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
    struct bstinfo{
        int min_val;
        int max_val;
        bool isbst;
        int size;
        bstinfo(int minval,int maxval,bool bst,int s):min_val(minval),max_val(maxval),isbst(bst),size(s){}
    };
    struct bstinfo* largest_bst(TreeNode* root){
        if(root==NULL){
            return new bstinfo(INT_MAX,INT_MIN,true,0);
        }
        bstinfo* left = largest_bst(root->left);
        bstinfo* right = largest_bst(root->right);
        bstinfo* info;
        if(left->isbst&&right->isbst&&left->max_val<root->val&&right->min_val>root->val){
            info = new bstinfo(min(root->val,min(left->min_val,right->min_val)),max(root->val,max(left->max_val,right->max_val)),true,left->size+right->size+1);
            return info;
        }else{
            info = new bstinfo(INT_MAX,INT_MIN,false,max(left->size,right->size));
        }
        delete left;
        delete right;
        return info;
    }
    int largestBSTSubtree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        bstinfo* info = largest_bst(root);
        return info->size;
    }
};
