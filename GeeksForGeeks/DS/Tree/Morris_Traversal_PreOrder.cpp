// { Driver Code Starts
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <map>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;

	Node(int x) {
		data = x;
		left = NULL;
		right = NULL;
	}
};
<<<<<<< HEAD
void morrisTraversalPreOrder(struct node *root){
	if(root==NULL){
		return;
	}
	while(root){
		if(root->left==NULL){
			cout<<root->data<<" ";
			root = root->right;
		}else{
			struct node *current = root->left;
			while(current->right&&current->right!=root){
				current = current->right;
			}
			if(current->right==root){
				current->right = NULL;
				root = root->right;
			}else{
				cout<<root->data<<" ";
				current->right = root;
				root = root->left;
			}
		}
	}
}
int main(){

}
=======
>>>>>>> 998fa9023daeefc5ec78c2828c69302513ec48e4
