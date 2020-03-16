/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    vector<int> _inorder;
    void inorder(TreeNode* root,vector<int>& _inorder){
        if(root==NULL){
            return;
        }
        inorder(root->left,_inorder);
        _inorder.push_back(root->val);
        inorder(root->right,_inorder);
    }
    vector<int>::iterator itr;
    BSTIterator(TreeNode* root) {
        inorder(root,_inorder);
        itr = _inorder.begin();
    }

    /** @return the next smallest number */
    int next() {
        int result = *itr;
        itr++;
        return result;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(itr==_inorder.end()){
            return false;
        }
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
