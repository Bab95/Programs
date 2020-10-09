/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::flatten(TreeNode* root) {
    stack<TreeNode*> stk;
    TreeNode* head = NULL;
    TreeNode* q = NULL;
    stk.push(root);
    while(!stk.empty()){
        TreeNode* current = stk.top();
        stk.pop();
        if(current->right){
            stk.push(current->right);
            current->right = NULL;
        }
        if(current->left){
            stk.push(current->left);
            current->left = NULL;
        }
        if(head==NULL){
            head = current;
            q = current;
        }else{
            q->right = current;
            q = q->right;
        }
    }
    return head;
}
