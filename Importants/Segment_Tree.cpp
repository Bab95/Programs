#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <limits.h>
using namespace std;
struct node {
	int data;
	struct node *left, *right;
	int start_index;
	int end_index;
};
struct node *getnode(int data, int start_index, int end_index) {
	struct node *tmp = (struct node *)malloc(sizeof(struct node));
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->data = data;
	tmp->end_index = end_index;
	tmp->start_index = start_index;
	return tmp;
}
struct node *buildTree(int arr[], int sum[], int low, int high) {
	if (low == high) {
		struct node *root = getnode(arr[low], low, low);
		return root;
	}
	if (low<high) {
		struct node *root = getnode(sum[high + 1] - sum[low], low, high);
		int mid = (low + high) / 2;
		root->left = buildTree(arr, sum, low, mid);
		root->right = buildTree(arr, sum, mid + 1, high);
		return root;
	}
	return NULL;
}
int get_query(struct node *root, int start_index, int end_index) {
	if (root->start_index == start_index&&root->end_index == end_index) {
		return root->data;
	}
	int mid = (root->start_index + root->end_index) / 2;
	if (start_index > mid) {
		return get_query(root->right, start_index, end_index);
	}
	else if (start_index <= mid&&end_index > mid) {
		int left = get_query(root->left, start_index, mid);
		int right = get_query(root->right, mid + 1, end_index);
		return left + right;
	}
	else if(end_index<=mid) {
		return get_query(root->left, start_index, end_index);
	}
	return INT_MAX;
}
void update_query(struct node *root, int index, int target, int arr[]) {
	if (root == NULL) {
		return;
	}
	if (root->start_index == index&&root->end_index == target) {
		root->data = root->data - arr[index] + target;
		return;
	}
	int mid = (root->start_index + root->end_index) / 2;
	root->data = root->data - arr[index] + target;
	if (index <= mid) {
		update_query(root->left, index, target, arr);
	}
	else if (index > mid) {
		update_query(root->right, index, target, arr);
	}

}
int main() {
	int n;
	freopen("input.txt", "r", stdin);
	cin >> n;
	int *arr = new int[n];
	int *sum = new int[n + 1];
	sum[0] = 0;
	for (int i = 0;i<n;i++) {
		cin >> arr[i];
		sum[i + 1] = sum[i] + arr[i];
	}
	struct node *root = buildTree(arr, sum, 0, n - 1);
	cout << get_query(root, 3, 7)<<endl;
	update_query(root, 7, 10, arr);
	cout << get_query(root, 2, 8)<<endl;
	return 0;
}
