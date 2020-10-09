/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool leaf(TreeNode* root){
    if(root==NULL){
        return false;
    }
    if(root->left==NULL&&root->right==NULL){
        return true;
    }
    return false;
}
void find_path_sum(TreeNode* root,vector<int> current,vector<vector<int>>& ans,int sum){
    if(root==NULL){
        return;
    }
    if(leaf(root)&&sum-root->val==0){
        current.push_back(root->val);
        ans.push_back(current);
        current.pop_back();
        return;
    }
    current.push_back(root->val);
    find_path_sum(root->left,current,ans,sum-root->val);
    find_path_sum(root->right,current,ans,sum-root->val);
    current.pop_back();
}
vector<vector<int> > Solution::pathSum(TreeNode* root, int sum) {
    vector<int> current;
    vector<vector<int> > ans;
    find_path_sum(root,current,ans,sum);
    return ans;
}
