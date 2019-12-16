#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
struct Node {
	int data;
	Node *left, *right;

	Node(int x) {
		data = x;
		left = NULL;
		right = NULL;
	}
};
void insert(Node *root, int a1, int a2, char lr) {
	if (root == NULL)
		return;
	if (root->data == a1) {
		switch (lr) {
		case 'L':root->left = new Node(a2);
			break;
		case 'R':root->right = new Node(a2);
			break;
		}
	}
	else {
		insert(root->left, a1, a2, lr);
		insert(root->right, a1, a2, lr);
	}
}
Node *convertToDLL(Node *root, Node **head_ref);
int main() {
	freopen("input.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		Node *root = NULL;
		while (n--) {
			int a1, a2;
			char lr;
			cin >> a1 >> a2;
			scanf(" %c", &lr);
			if (root == NULL) {
				root = new Node(a1);
				switch (lr) {
				case 'L':root->left = new Node(a2);
					break;
				case 'R':root->right = new Node(a2);
					break;
				}
			}
			else {
				insert(root, a1, a2, lr);
			}
		}

		Node *head = NULL;
		root = convertToDLL(root, &head);

		while (head->right != NULL) {
			cout << head->data << " ";
			head = head->right;
		}

		cout << head->data << endl;
		while (head != NULL) {
			cout << head->data << " ";
			head = head->left;
		}
		cout << endl;
	}
}

/*This is a function problem.You only need to complete the function given below*/
/*Complete the function below
Node is as follows:
struct Node{
int data;
Node *left,*right;

Node(int x){
data = x;
left = NULL;
right = NULL;
}
};
*/
bool is_leaf(struct Node *root) {
	if (root != NULL) {
		if (root->left == NULL&&root->right == NULL) {
			return true;
		}
	}
	return false;
}
void my_inorder(Node *root, Node **head_ref, Node **tail_ref) {
	if (root == NULL) {
		return;
	}
	if (root->left == NULL&&root->right == NULL) {
		return;
	}
	my_inorder(root->left, head_ref, tail_ref);
	if (root->left != NULL&&is_leaf(root->left)) {
		if (*head_ref == NULL) {
			*head_ref = root->left;
			*tail_ref = *head_ref;
			//root->left = NULL;
		}
		else {
			//Node *q = *tail_ref;
			(*tail_ref)->right = root->left;
			root->left->left = (*tail_ref);
			//root->left = NULL;
			*tail_ref = (*tail_ref)->right;
		}
	}
	my_inorder(root->right, head_ref, tail_ref);
	if (root->right != NULL&&is_leaf(root->right)) {
		if (*head_ref == NULL) {
			*head_ref = root->right;
			*tail_ref = *head_ref;
			//root->right = NULL;
		}
		else {
			(*tail_ref)->right = root->right;
			//root->right = NULL;
			root->right->left = (*tail_ref);
			(*tail_ref) = (*tail_ref)->right;
		}
	}
}
Node *convertToDLL(Node *root, Node **head_ref)
{
	//add code here.
	if (root == NULL) {
		return NULL;
	}
	struct Node **tail_ref;
	struct Node *q = NULL;
	tail_ref = &q;
	my_inorder(root, head_ref, tail_ref);
	//(*tail_ref)->right = *head_ref;
	//(*head_ref)->left = (*tail_ref);
	return root;
}
