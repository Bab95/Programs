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

// The main function to reverse alternate Nodes of a binary tree
void reverseAlternate(struct Node *root);

// A utility function to print indorder traversal of a
// binary tree
void printInorder(struct Node *root)
{
	if (root == NULL) return;
	printInorder(root->left);
	cout << root->data << " ";
	printInorder(root->right);
}
/* Driver program to test above functions*/
int main()
{
	int t;
	freopen("input.txt", "r", stdin);
	scanf("%d\n", &t);
	while (t--)
	{
		map<int, Node*> m;
		int n;
		scanf("%d\n", &n);
		Node *root = NULL;
		while (n--)
		{
			Node *parent;
			char lr;
			int n1, n2;
			scanf("%d %d %c", &n1, &n2, &lr);
			//  cout << n1 << " " << n2 << " " << (char)lr << endl;
			if (m.find(n1) == m.end())
			{
				parent = new Node(n1);
				m[n1] = parent;
				if (root == NULL)
					root = parent;
			}
			else
				parent = m[n1];

			Node *child = new Node(n2);
			if (lr == 'L')
				parent->left = child;
			else
				parent->right = child;
			m[n2] = child;
		}
		reverseAlternate(root);
		printInorder(root);

		cout << endl;

	}
	return 0;
}

// } Driver Code Ends
/* A binary tree Node
struct Node
{
int data;
Node* left, * right;
}; */
#include <queue>
void levelOrder(Node *root) {
	queue<Node*> q;
	q.push(root);
	while (!q.empty()) {
		Node *tmp = q.front();
		q.pop();
		cout << tmp->data << " ";
		if (tmp->left) {
			q.push(tmp->left);
		}
		if (tmp->right) {
			q.push(tmp->right);
		}
	}
}
void reverseAlternate(Node *root)
{
	//Your code here
	cout << "before inorder-";
	printInorder(root);
	cout << "---------"<<endl;
	if (root == NULL || root->left == NULL) {
		return;
	}
	if (root->left->left == NULL) {
		int tmp = root->left->data;
		root->left->data = root->right->data;
		root->right->data = tmp;
		return;
	}
	/*queue<pair<int,Node*> > q;
	pair<int,Node*> p;
	p.first = 0;
	p.second = root;*/
	//int level = 0;
	queue<Node*> q;
	q.push(root->left);
	q.push(root->right);
	bool even_level = false;
	/*int tmp = root->left->data;
	root->left->data = root->right->data;
	root->right->data = tmp;*/
	vector<Node*> vec;
	q.push(NULL);
	struct Node *tmp1;
	struct Node *tmp2;
	while (!q.empty() && q.front() != NULL) {
		while (q.front() != NULL) {
			tmp1 = q.front();
			q.pop();
			tmp2 = q.front();
			q.pop();
			if (even_level == false) {
				int tmp = tmp1->data;
				tmp1->data = tmp2->data;
				tmp2->data = tmp;
			}
			if (tmp1->left) {
				q.push(tmp1->left);
			}
			if (tmp2->right) {
				q.push(tmp2->right);
			}
			if (tmp1->right) {
				q.push(tmp1->right);
			}
			if (tmp2->left) {
				q.push(tmp2->left);
			}
		}
		q.pop();
		q.push(NULL);
		even_level = !even_level;
	}

}
