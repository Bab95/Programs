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
    pair<double,double> calculate(TreeNode* root,double& ans){
        if(root==NULL){
            return {0,0};
        }
        if(root->left==NULL&&root->right==NULL){
            ans = max(ans,(double)root->val);
            return {(double)root->val,1.0};
        }
        pair<double,double> _left = calculate(root->left,ans);
        pair<double,double> _right = calculate(root->right,ans);
        double _l=INT_MIN,_r=INT_MIN;
        double total_sum = _left.first + _right.first + (double)root->val;
        double total_nodes = _left.second + _right.second + 1.0;
        //cout<<root->val<<" "<<ans<<" "<<total_sum<<" "<<total_nodes<<endl;
        double current_avg = total_sum/total_nodes;
        ans = max(ans,current_avg);
        return {total_sum,total_nodes};
    }
    double maximumAverageSubtree(TreeNode* root) {
        double ans = INT_MIN;
        pair<double,double> res = calculate(root,ans);
        ans = max(res.first/res.second,ans);
        return ans;
    }
};

/*
[2,6,3,null,5,12,7,null,null,0,4,null,10,null,null,11,null,null,9,null,1,null,8]
[8,11,25,0,6,null,22,34,18,1,4,14,null,15,29,20,30,31,16,21,26,null,28,null,null,10,32,33,null,7,null,27,null,null,null,24,null,12,5,13,17,null,null,3,null,null,23,null,null,null,null,2,null,null,null,null,null,null,null,null,19,null,null,null,null,null,null,null,9]
[5,6,1]
*/
