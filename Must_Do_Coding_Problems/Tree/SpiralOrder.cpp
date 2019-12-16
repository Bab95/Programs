#include <iostream>
#include <stack>
#include <queue>
using namespace std;
struct node {
	int data;
	struct node *left, *right;
};
struct node *getnode(int data) {
	struct node *tmp = (struct node *)malloc(sizeof(struct node));
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->data = data;
	return tmp;
}
void spiralorder(struct node *root) {
	queue<struct node *> q;
	stack<struct node *> s;
	s.push(root);
	struct node *tmp = NULL;
	while (!s.empty() || !q.empty()) {
		while (!s.empty()) {
			tmp = s.top();
			s.pop();
			if (tmp->left) {
				q.push(tmp->left);
			}
			if (tmp->right) {
				q.push(tmp->right);
			}
			cout << tmp->data << " ";
		}
		while (!q.empty()) {
			tmp = q.front();
			q.pop();
			if (tmp->left) {
				s.push(tmp->left);
			}
			if (tmp->right) {
				s.push(tmp->right);
			}
			cout << tmp->data << " ";
		}
	}
}
int main() {
	struct node *root = getnode(1);
	root->left = getnode(2);
	root->right = getnode(3);
	root->right->right = getnode(4);
	root->right->left = getnode(5);
	root->left->right = getnode(6);
	root->left->left = getnode(7);
	spiralorder(root);
	system("pause");
}
