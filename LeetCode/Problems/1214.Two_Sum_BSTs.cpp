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
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        TreeNode* r1 = root1;
        TreeNode* r2 = root2;
        stack<TreeNode*> stk1;
        stack<TreeNode*> stk2;
        while((!stk1.empty()||r1!=NULL)||(stk2.empty()||r2!=NULL)){
            while(r1!=NULL){
                stk1.push(r1);
                r1 = r1->left;
            }
            while(r2!=NULL){
                stk2.push(r2);
                r2 = r2->right;
            }
            if(!stk1.empty()&&!stk2.empty()){
                cout<<stk1.top()->val<<" "<<stk2.top()->val<<endl;
                if(stk1.top()->val+stk2.top()->val==target){
                    return true;
                }else if(stk1.top()->val+stk2.top()->val>target){
                    r2 = stk2.top();
                    stk2.pop();
                    r2 = r2->left;
                }else if(stk1.top()->val+stk2.top()->val<target){
                    r1 = stk1.top();
                    stk1.pop();
                    r1 = r1->right;
                }
            }else{
                cout<<"ldjksnfl"<<endl;
                return false;
            }
        }
        return false;
    }
};
