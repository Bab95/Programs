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
    int store_sum(TreeNode* root,unordered_map<TreeNode*,long int>& mmap){
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL&&root->right==NULL){
            return mmap[root] = root->val;
        }
        long int current = store_sum(root->left,mmap) + root->val + store_sum(root->right,mmap);
        return mmap[root] = current;
    }
    bool checkpartition(TreeNode* root,unordered_map<TreeNode*,long int>& mmap,long int tree_sum){
        if(root==NULL){
            return false;
        }
        if(root->left!=NULL){
            if(tree_sum-mmap[root->left]==mmap[root->left]){
                return true;
            }
        }
        if(root->right!=NULL){
            if(tree_sum-mmap[root->right]==mmap[root->right]){
                return true;
            }
        }
        bool left = checkpartition(root->left,mmap,tree_sum);
        bool right = checkpartition(root->right,mmap,tree_sum);
        return left||right;
    }

    bool checkEqualTree(TreeNode* root) {
        unordered_map<TreeNode*,long int> mmap;
        store_sum(root,mmap);
        /*for(auto it=mmap.begin();it!=mmap.end();++it){
            cout<<it->first->val<<" "<<it->second<<endl;
        }*/
        bool ans = checkpartition(root,mmap,mmap[root]);
        return ans;
    }
};
/*
[5,10,10,null,null,2,3]
[6,2,8,0,4,7,9,null,null,2,6]
[1,2,10,null,null,2,20]

*/
