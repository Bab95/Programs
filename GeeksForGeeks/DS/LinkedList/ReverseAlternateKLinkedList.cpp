#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
struct node {
	int data;
	struct node *next;
};
struct node *getnode(int data) {
	struct node *tmp = (struct node *)malloc(sizeof(struct node));
	tmp->next = NULL;
	tmp->data = data;
	return tmp;
}
struct node* insert(int data, struct node *head) {
	if (head == NULL) {
		return getnode(data);
	}
	struct node *p = getnode(data);
	p->next = head;
	head = p;
	return head;
}
void printlist(struct node *p) {
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
struct node *reverseALTk(struct node *head, int k) {
	struct node *ptr = head;
	struct node *prev, *next;
	prev = NULL;
	next = NULL;
	int i = 0;
	while (ptr != NULL&&i < k) {
		next = ptr->next;
		ptr->next = prev;
		prev = ptr;
		ptr = next;
		i++;
	}
	head->next = ptr;
	head = prev;
	i = 0;
	while (ptr != NULL&&i < k - 1) {
		ptr = ptr->next;
		i++;
	}
	if (ptr) {
		ptr->next = reverseALTk(ptr->next, k);
	}
	return head;
}
int main() {
	int t, n, k;
	freopen("input.txt", "r", stdin);
	cin >> t;
	while (t--) {
		cin >> n >> k;
		int tmp;
		struct node *head = NULL;
		for (int i = 0;i < n;i++) {
			cin >> tmp;
			head = insert(tmp, head);
		}
		printlist(head);
		head = reverseALTk(head, k);
		printlist(head);
	}
	system("pause");
}
