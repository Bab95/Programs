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
    bool ans = false;
    bool is_subtree(TreeNode* s,TreeNode* t){
        if(s==NULL&&t==NULL){
            return true;
        }
        if(s==NULL||t==NULL){
            return false;
        }
        if(s->val==t->val){
            bool left = is_subtree(s->left,t->left);
            bool right = is_subtree(s->right,t->right);
            return left&&right;
        }
        return false;
    }
    void preorder(TreeNode* r1,TreeNode*r2){
        if(r1==NULL){
            return;
        }
        if(r1->val==r2->val){
            ans = ans || is_subtree(r1,r2);
            if(ans==true){
                return;
            }
        }
        preorder(r1->left,r2);
        preorder(r1->right,r2);
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        preorder(s,t);
        return ans;
    }
};

//Solution 2: Faster....
//Using KPM string Matching Algorithm......
//Store PreOrder with NULL as a value as well and use to find if t's preorder is
// is subarray of S.
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
    void preorder(TreeNode* root,vector<int>& tree){
        if(root==NULL){
            tree.push_back(INT_MAX);
            return;
        }
        tree.push_back(root->val);
        preorder(root->left,tree);
        preorder(root->right,tree);
    }
    bool Kmp_array(vector<int>& text,vector<int>& pattern){
        vector<int> longestSuffixPrefix(pattern.size(),0);
        int i = 0;
        int j = 1;
        //building SuffixPrefix array..
        while(j<pattern.size()){
            if(pattern[j]==pattern[i]){
                longestSuffixPrefix[j] = i+1;
                i++;
                j++;
            }else{
                if(i>0){
                    i = longestSuffixPrefix[i-1];
                }else{
                    longestSuffixPrefix[j] = 0;
                    j++;
                }
            }
        }
        int index = 0;
        j = 0;
        while(index<text.size()){
            if(text[index]==pattern[j]){
                index++;
                j++;
            }
            if(j==pattern.size()){
                return true;
            }
            else if(index<text.size()&&text[index]!=pattern[j]){
                if(j>0){
                    j = longestSuffixPrefix[j-1];
                }else{
                    index++;
                }
            }
        }
        return false;
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        vector<int> sp,tp;
        preorder(s,sp);
        preorder(t,tp);
        if(Kmp_array(sp,tp)){
            return true;
        }
        return false;
    }
};
