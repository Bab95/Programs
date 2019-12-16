/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/
#include <limits.h>
    bool BST_check_function(Node *root,int maxlimit,int minlimit){
        if(root==NULL){
            return true;
        }
        if(root->data<maxlimit&&root->data>minlimit){
            return BST_check_function(root->left,root->data,minlimit)&&BST_check_function(root->right,maxlimit,root->data);
        }
        return false;
    }
	bool checkBST(Node* root) {
		return BST_check_function(root,INT_MAX,INT_MIN);
	}
