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
    double ceil(double target){
        double diff = (double)(target - (double)((long int)target));
        if(diff>0){
            return (long int)target + 1;
        }
        return target;
    }
    double floor(double target){
        return (long int)target;
    }
    void find_value(TreeNode* root,double target,double& diff,long int _c,long int _f,long int& ans){
        if(!root){
            return;
        }
        double current_diff = abs((double)root->val-target);
        if(current_diff<diff){
            diff = current_diff;
            ans = root->val;
        }
        if(_c<=root->val){
            find_value(root->left,target,diff,_c,_f,ans);
        }else if(_f>=root->val){
            find_value(root->right,target,diff,_c,_f,ans);
        }
    }
    int closestValue(TreeNode* root, double target) {
        long int _c = ceil(target);
        long int _f = floor(target);
        double diff = LONG_MAX;
        long int ans = INT_MAX;
        find_value(root,target,diff,_c,_f,ans);
        return (int)ans;
    }
};
