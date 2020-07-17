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
    void inorder(TreeNode* root,priority_queue<int,vector<int>,greater<int> >& pq){
        if(root==NULL){
            return;
        }
        inorder(root->left,pq);
        pq.push(root->val);
        inorder(root->right,pq);
    }
    int findSecondMinimumValue(TreeNode* root) {
        priority_queue<int,vector<int>,greater<int> > pq;
        inorder(root,pq);
        int t = pq.top();
        pq.pop();
        while(!pq.empty()){
            if(pq.top()==t){
                pq.pop();
            }else{
                t = pq.top();
                return t;
            }
        }
        if(pq.empty()){
            return -1;
        }
        return -1;
    }
};
