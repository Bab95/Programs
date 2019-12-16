#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
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

Node *buildTree(int a[], int b[], int str, int end);
int preIndex = 0;
void printPostOrder(Node *root) {
	if (root == NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout << root->data << " ";
}
int main() {
	int t;
	freopen("input.txt", "r", stdin);
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		preIndex = 0;
		Node *root = NULL;
		int *a = new int[n];
		int *b = new int[n];
		for (int i = 0;i<n;i++)
			cin >> a[i];
		for (int i = 0;i<n;i++)
			cin >> b[i];
		root = buildTree(a, b, 0, n - 1);
		printPostOrder(root);
		cout << endl;
	}
	system("pause");
}/*This is a function problem.You only need to complete the function given below*/
 /*Complete the code here.
 Node is as follows:
 struct Node
 {
 int data;
 Node* left;
 Node* right;
 };
 */
int index(int in[], int value, int instart, int inend) {
	for (int i = instart;i <= inend;i++) {
		if (in[i] == value) {
			return i;
		}
	}
	return -1;
}
Node* getnode(int data) {
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->data = data;
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}
int *preorderArray(int in[], int instart, int inend, int pre[], int n) {
	unsigned int size = inend - instart + 1;
	int* pre_new = (int*)malloc(sizeof(int)*size);
	int k = 0;
	for (int i = 0;i<n;i++) {
		for (int j = instart;j <= inend;j++) {
			if (pre[i] == in[j]) {
				pre_new[k] = in[j];
				k++;
				break;
			}
		}
	}
	return pre_new;
}
Node* buildTreeUtil(int in[], int pre[], int instart, int inend, int n) {
	if (instart>inend) {
		return NULL;
	}
	int value = pre[0];
	int inIndex = index(in, value, instart, inend);
	Node *root = getnode(value);
	int* pre_left = preorderArray(in, instart, inIndex - 1, pre, n);
	int* pre_right = preorderArray(in, inIndex + 1, inend, pre, n);
	root->left = buildTreeUtil(in, pre_left, instart, inIndex - 1,n);
	root->right = buildTreeUtil(in, pre_right, inIndex + 1, inend,n);
	return root;
}
Node* buildTree(int in[], int pre[], int instart, int inend)
{
	//add code here.
	int n = inend - instart + 1;
	return buildTreeUtil(in, pre, instart, inend, n);

}
