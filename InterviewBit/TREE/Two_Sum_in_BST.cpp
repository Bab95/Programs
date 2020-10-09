/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::t2Sum(TreeNode* A, int B) {
    TreeNode* r1 = A;
    TreeNode* r2 = A;
    stack<TreeNode*> stk1,stk2;
    stk1.push(r1);
    stk2.push(r2);
    while(true){
        while(r1){
            stk1.push(r1);
            r1 = r1->left;
        }
        while(r2){
            stk2.push(r2);
            r2 = r2->right;
        }
        r1 = stk1.top();
        stk1.pop();
        r2 = stk2.top();
        stk2.pop();
        if(r1==r2&&r1!=NULL){
            return 0;
        }else if(r1->val+r2->val==B){
            return 1;
        }else if(r1->val+r2->val<B){
            stk2.push(r2);
            r2 = NULL;
            r1 = r1->right;
        }else if(r1->val+r2->val>B){
            stk1.push(r1);
            r1 = NULL;
            r2 = r2->left;
        }
    }
    return 0;
}
