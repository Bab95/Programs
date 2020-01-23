#include <iostream>
using namespace std;
struct node{
	int data;
	struct node *left, *right;
};
struct node *getnode(int data){
	struct node *tmp = (struct node *)malloc(sizeof(struct node));
	tmp->data = data;
	tmp->left = tmp->right = NULL;
	return tmp;
}
int mod(int a){
	if (a < 0){
		return -1 * a;
	}
	return a;
}
bool continuesTree(struct node *root,int parentdata){
	if (root == NULL){
		return true;
	}
	if (mod(root->data - parentdata) == 1){
		return continuesTree(root->left, root->data) && continuesTree(root->right, root->data);
	}
	return false;
}
struct node* buildtree(){
	struct node *root = getnode(3);
	root->left = getnode(2);
	root->right = getnode(4);
	root->left->left = getnode(1);
	root->left->right = getnode(3);
	root->right->right = getnode(5);
	return root;
}
int main(){
	struct node *root = NULL;
	root = buildtree();
	if (continuesTree(root->left, root->data) && continuesTree(root->right, root->data)){
		cout << "Yes" << endl;
	}
	else{
		cout << "No" << endl;
	}
	return 0;
}
