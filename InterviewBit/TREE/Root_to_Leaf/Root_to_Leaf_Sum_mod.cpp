/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int mod(string& num){
    int res = 0;
    for(int i=0;i<num.length();++i){
        res = (res*10 + ((int)num[i]-'0'))%1003;
    }
    return res;
}
bool leaf(TreeNode* root){
    if(root==NULL){
        return false;
    }
    if(root->left==NULL&&root->right==NULL){
        return true;
    }
    return false;
}
void find_num(TreeNode* root,int& sum,string current){
    if(root==NULL){
        return;
    }
    if(leaf(root)){
        current.push_back(root->val+'0');
        sum += mod(current);
        sum %= 1003;
        current.pop_back();
        return;
    }
    current.push_back(root->val+'0');
    find_num(root->left,sum,current);
    find_num(root->right,sum,current);
    if(current.length()!=0){
        current.pop_back();
    }

}
int Solution::sumNumbers(TreeNode* root) {
    int sum = 0;
    string current = "";
    find_num(root,sum,current);
    return sum%1003;
}
