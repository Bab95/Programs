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
    void storeBst(TreeNode* root,vector<int>& bst){
        if(root==NULL){
            return;
        }
        storeBst(root->left,bst);
        bst.push_back(root->val);
        storeBst(root->right,bst);
    }
    TreeNode* buildTree(vector<int>& bst,int left,int right){
        if(right<left){
            return NULL;
        }
        int mid = (left+right)/2;
        TreeNode* root = new TreeNode(bst[mid]);
        root->left = buildTree(bst,left,mid-1);
        root->right = buildTree(bst,mid+1,right);
        return root;
    }
    void delete_prev(TreeNode* root){
        if(root==NULL){
            return;
        }
        delete_prev(root->left);
        delete_prev(root->right);
        //cout<<"deleting "<<root->val<<endl;
        if(root!=NULL){
            cout<<"deleteing "<<root->val<<endl;
            delete (root);
            if(root==NULL){
                cout<<"delted";
            }
        }

    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> bst;
        storeBst(root,bst);
        TreeNode* ans = buildTree(bst,0,bst.size()-1);
        //can't delete here because delete operator need to be overloaded as it is userdefined data type;
        //delete_prev(root);
        return ans;
    }
};
