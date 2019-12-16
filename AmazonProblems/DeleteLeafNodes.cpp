#include <iostream>
using namespace std;
struct node {
	int data;
	struct node *left, *right;
};
struct node *getnode(int data) {
	struct node *tmp = (struct node *)malloc(sizeof(struct node));
	tmp->left = tmp->right = NULL;
	tmp->data = data;
	return tmp;
}struct node *deleteleaves(struct node *root) {
	if (root != NULL) {
		if (root->left == NULL&&root->right == NULL) {
			cout << root->data << " ";
			free(root);
			return NULL;
		}
		else {
			root->left = deleteleaves(root->left);
			root->right = deleteleaves(root->right);
		}
	}
	return root;
}
int main() {
	struct node *root = getnode(1);
	root->left = getnode(2);
	root->right = getnode(3);
	root->left->left = getnode(4);
	root->left->right = getnode(5);
	root->left->right->left = getnode(9);
	root->left->right->left->right = getnode(10);
	root->right->left = getnode(6);
	root->right->right = getnode(7);
	root->right->left->left = getnode(8);
	while (root != NULL) {
		root = deleteleaves(root);
		cout << endl;
	}
	if (root == NULL) {
		cout <<endl<< "Deleted" << endl;
	}
}
