/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    TreeNode* BuildTree(vector<ListNode*>& tree,int low,int high){
        if(low<=high){
            int mid = (low+high)/2;
            TreeNode* root = new TreeNode(tree[mid]->val);
            root->left = BuildTree(tree,low,mid-1);
            root->right = BuildTree(tree,mid+1,high);
            return root;
        }
        return NULL;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<ListNode*> tree;
        ListNode* p = head;
        while(p!=NULL){
            tree.push_back(p);
            p = p->next;
        }
        TreeNode* treeNode = BuildTree(tree,0,tree.size()-1);
        return treeNode;
    }
};
