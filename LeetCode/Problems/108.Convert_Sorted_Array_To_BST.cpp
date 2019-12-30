/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode* getnode(int data){
    /*struct TreeNode *tmp = (struct TreeNode*)malloc(sizeof(TreeNode));*/
    struct TreeNode *tmp = new TreeNode(data);
    //tmp->val = data;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}
class Solution {
public:
    TreeNode* converttoTree(vector<int>& nums,int left,int right){
        if(left>right){
            return NULL;
        }
        int mid = (left+right+1)/2;
        int data = nums[mid];
        struct TreeNode* root = getnode(data);
        root->left = converttoTree(nums,left,mid-1);
        root->right = converttoTree(nums,mid+1,right);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return converttoTree(nums,0,n-1);
    }
};
