/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool check(TreeNode* root,ListNode* head){
        if(root==NULL){
            if(head==NULL){
                return true;
            }
            return false;
        }else{
            if(head==NULL){
                return true;
            }
        }
        bool current = (root->val==head->val)?true:false;
        bool left = check(root->left,head->next);
        bool right = check(root->right,head->next);
        return current&&(left||right);
    }
    bool preorder(TreeNode* root,ListNode* head){
        if(root==NULL){
            return false;
        }
        if(check(root,head)){
            return true;
        }
        bool left = preorder(root->left,head);
        bool right = preorder(root->right,head);
        return left||right;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        return preorder(root,head);
    }
};
