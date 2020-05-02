/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isleaf(TreeNode* root){
        if(root==NULL){
            return false;
        }
        if(root->left==NULL&&root->right==NULL){
            return true;
        }
        return false;
    }
    void findsum(TreeNode* root,vector<int>& path,int current,vector<vector<int> >& result,int sum){
        if(root==NULL){
            return;
        }
        //cout<<root->val<<" "<<current<<endl;
        if(isleaf(root)&&current+root->val==sum){
            path.push_back(root->val);
            result.push_back(path);
            path.pop_back();
            return;
        }
        path.push_back(root->val);
        findsum(root->left,path,current+root->val,result,sum);
        findsum(root->right,path,current+root->val,result,sum);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        int current = 0;
        vector<vector<int> > result;
        findsum(root,path,current,result,sum);
        return result;
    }
};
