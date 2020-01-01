/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode* getNode(int data){
    TreeNode* tmp =  (struct TreeNode*)malloc(sizeof(TreeNode));
    tmp->val = data;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1==NULL&&t2==NULL){
            return NULL;
        }
        int v1 = (t1==NULL)?0:t1->val;
        int v2 = (t2==NULL)?0:t2->val;
        TreeNode* root = getNode(v1+v2);
        if(root!=NULL){
            if(t1==NULL&&t2!=NULL){
                root->left = mergeTrees(t1,t2->left);
                root->right = mergeTrees(t1,t2->right);
            }else if(t1!=NULL&&t2==NULL){
                root->left = mergeTrees(t1->left,t2);
                root->right = mergeTrees(t1->right,t2);
            }else{
                root->left = mergeTrees(t1->left,t2->left);
                root->right = mergeTrees(t1->right,t2->right);
            }
        }
        return root;
    }
};
