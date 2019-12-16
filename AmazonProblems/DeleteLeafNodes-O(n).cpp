#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;
struct node {
	int data;
	struct node *left, *right, *parent;
};
struct node *getnode(int data) {
	struct node *tmp = (struct node *)malloc(sizeof(struct node));
	tmp->left = tmp->right = tmp->parent = NULL;
	tmp->data = data;
	return tmp;
}
void inorder(struct node *root, queue<node*> &q) {
	if (root == NULL) {
		return;
	}
	inorder(root->left,q);
	if (root->left == NULL&&root->right == NULL) {
		q.push(root);
	}
	inorder(root->right,q);
}
void deleteLeaves(struct node *root) {
	queue<node*> q;
	inorder(root, q);
	struct node *tmp;
	while (!q.empty()) {
		tmp = q.front();
		q.pop();
		cout << tmp->data << " ";
		if (tmp->parent == NULL) {
			break;
		}
		if (tmp == tmp->parent->left) {
			tmp->parent->left = NULL;
		}
		else if (tmp == tmp->parent->right) {
			tmp->parent->right = NULL;
		}
		if (tmp->parent->left == NULL&&tmp->parent->right == NULL) {
			q.push(tmp->parent);
		}
		tmp->parent = NULL;
		delete tmp;
	}
}
int main() {
	struct node *root;
	struct node *p;
	root = getnode(1);
	root->left = getnode(2);
	root->left->parent = root;
	root->right = getnode(3);
	root->right->parent = root;
	p = root->left;
	p->left = getnode(4);
	p->left->parent = p;
	p->right = getnode(5);
	p->right->parent = p;
	p = p->right;
	p->left = getnode(8);
	p->left->parent = p;
	p = root->right;
	p->left = getnode(6);
	p->left->parent = p;
	p->right = getnode(7);
	p->right->parent = p;
	p = p->left;
	p->right = getnode(9);
	p->right->parent = p;
	deleteLeaves(root);
	return 0;
}
