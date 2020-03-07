/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
public:
    vector<int> values;
    FindElements(TreeNode* root) {
        root->val = 0;
        //values.push_back(0);
        recoverTree(root,0,values);

    }
    void recoverTree(TreeNode* root,int val,vector<int>& values){
        if(root==NULL){
            return;
        }
        values.push_back(val);
        recoverTree(root->left,2*val+1,values);
        recoverTree(root->right,2*val+2,values);
    }
    bool find(int target) {
      for(int i=0;i<values.size();i++){
          if(target==values[i]){
              return true;
          }
      }
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
