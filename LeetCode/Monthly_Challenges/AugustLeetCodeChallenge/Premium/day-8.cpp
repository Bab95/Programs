/*
Problem statement:
Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

Note:

Given target value is a floating point.
You are guaranteed to have only one unique value in the BST that is closest to the target.
Input: root = [4,2,5,1,3], target = 3.714286

   4
  / \
 2   5
/ \
1   3

Output: 4
*/

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
    double ceiling(double x){
        double diff = (double)(x - (double)((long int)x));
        if(diff==0){
            return x;
        }
        return (double)((long int)x + 1);
    }
    double floor(double x){
        return (long int)x;
    }
    void find_value(TreeNode* root,double target,int& ans,double& diff,double _c,double _f){
        if(!root){
            return;
        }
        double _diff = (double)((double)root->val-target);
        _diff = abs(_diff);
        if(_diff<diff){
            diff = _diff;
            ans = root->val;
        }
        if(root->val>=_c){
            find_value(root->left,target,ans,diff,_c,_f);
        }else if(root->val<=_f){
            find_value(root->right,target,ans,diff,_c,_f);
        }

    }
    int closestValue(TreeNode* root, double target) {
        double diff = 9223372036854775807.0;
        int ans = INT_MAX;
        double c = (double)ceiling(target);
        double f = (double)floor(target);
        find_value(root,target,ans,diff,c,f);
        return ans;
    }
};
/*
ceiling -> next integer...
floor -> previous integer....
   8
   / \
  5   9
 / \   \
3   7   10
 \
  4

right call -> root->val < floor(target)
left call -> root->val >celing(target)

root->val >=floor(target)
root->val <celing(target) ->right....
4.7 ans ->5 , 4.....
if(root->val==floor(target))
[4,2,5,1,3]
4.714286
[4,2,5,1,3]
3.714286
[4,2,5,1,3]
5.714286
[0]
2147483648.0
[1500000000,1400000000]
-1500000000.0
*/
