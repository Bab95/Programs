/*class Solution {
public:
    bool BST(TreeNode* root,int left,int right,int* sum,vector<int>& path){
        if(root==NULL){
            return true;
        }
        if(root->val<=left||root->val>=right){
            return false;
        }
        *sum = *sum + root->val;
        path.push_back(root->val);
        return BST(root->left,left,root->val,sum,path)&&BST(root->right,root->val,right,sum,path);

    }
    void preorder(TreeNode* root,int *ans){
        if(root==NULL){
            return;
        }
        int current = 0;
        vector<int> path;
        if(BST(root,INT_MIN,INT_MAX,&current,path)&&current>*ans){
            *ans = current;
        }
        preorder(root->left,ans);
        preorder(root->right,ans);
    }
    int maxSumBST(TreeNode* root) {
        int ans = INT_MIN;
        preorder(root,&ans);
        return max(0,ans);
    }
};

TLE not optimized solution
*/



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
    struct node{
        int low;
        int high;
        bool bst;
        int sum;
        node(int l,int h,bool b,int s) : low(l),high(h),bst(b),sum(s){}
    };

    node* check(TreeNode* root,int& maxsum){
        if(root==NULL){
            node *ans = new node(INT_MAX,INT_MIN,true,0);
            return ans;
        }

        if(root->left==NULL&&root->right==NULL){
            maxsum = max(maxsum,root->val);
            node* ans = new node(root->val,root->val,true,root->val);
        }
        node* left = check(root->left,maxsum);
        node* right = check(root->right,maxsum);
        if(left->bst&&right->bst&&left->high<root->val&&right->low>root->val){
            int sum = root->val + left->sum + right->sum;
            int newlow = min(left->low,min(root->val,right->low));
            int newhigh = max(left->high,max(root->val,right->high));
            node* ans = new  node(newlow,newhigh,true,sum);
            maxsum = max(maxsum,sum);
            return ans;
        }
        return new node(INT_MAX,INT_MIN,false,0);
    }
    int maxSumBST(TreeNode* root) {
        int maxsum = 0;
        node *ans = check(root,maxsum);
        return maxsum;
    }
};
