#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node* next;

	node(int x) {
		data = x;
		next = NULL;
	}

};
void printList(struct node *node)
{
	while (node != NULL) {
		cout << node->data << ' ';
		node = node->next;
	}
	printf("\n");
}
void push(struct node** head_ref, int new_data)
{
	struct node* new_node = new node(new_data);
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}
struct node* makeUnion(struct node* head1, struct node* head2);
int main()
{
	long test;
	freopen("input.txt", "r", stdin);
	cin >> test;
	while (test--)
	{
		struct node* a = NULL;
		int n, m, tmp;
		cin >> n;
		for (int i = 0; i<n; i++)
		{
			cin >> tmp;
			push(&a, tmp);
		}
    mergeSort(&a);
	}
	system("pause");
	return 0;
}
void split(struct node *source, struct node **a, struct node **b) {
	struct node *slow, *fast;
	slow = source;
	fast = source->next;
	while (fast != NULL) {
		fast = fast->next;
		if (fast != NULL) {
			slow = slow->next;
			fast = fast->next;
		}
	}
	*a = source;
	*b = slow->next;
	slow->next = NULL;
	return;
}
struct node *Merge(struct node *a, struct node *b) {
	if (a == NULL) {
		return b;
	}
	else if (b == NULL) {
		return a;
	}
	struct node *result = NULL;
	if (a->data < b->data) {
		result = a;
		result->next = Merge(a->next, b);
	}
	else if (a->data == b->data) {
		result = a;
		result->next = Merge(a->next, b->next);
	}
	else if (a->data > b->data) {
		result = b;
		result->next = Merge(a, b->next);
	}
	return result;
}
void mergeSort(struct node **head) {
	struct node *root = *head;
	struct node *a;
	struct node *b;
	if (root == NULL || root->next == NULL) {
		return;
	}
	split(root, &a, &b);
	mergeSort(&a);
	mergeSort(&b);
	*head = Merge(a, b);
}
