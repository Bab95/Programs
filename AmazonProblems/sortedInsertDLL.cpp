#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
struct node {
	int data;
	struct node *prev, *next;
};
struct node *getnode(int data) {
	struct node *tmp = (struct node *)malloc(sizeof(struct node));
	tmp->next = tmp->prev = NULL;
	tmp->data = data;
	return tmp;
}
void insert(struct node **head,struct node **tail, int data) {
	struct node *p = getnode(data);
	if (*head == NULL) {
		*head = p;
		*tail = p;
		//(*head)->prev = NULL;
		return;
	}
	if (p->data < (*head)->data) {
		(*head)->prev = p;
		p->next = (*head);
		(*head) = p;
		return;
	}
	if (p->data > (*tail)->data) {
		(*tail)->next = p;
		p->prev = (*tail);
		(*tail) = p;
		return;
	}
	struct node *tmp = (*head);
	while (tmp->data < p->data) {
		tmp = tmp->next;
	}
	p->prev = tmp->prev;
	p->next = tmp;
	tmp->prev = p;
	p->prev->next = p;
	return;
}
void printlist(struct node *p) {
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
int main() {
	int t;
	int tmp, n;
	freopen("input.txt", "r", stdin);
	cin >> t;
	while (t--) {
		cin >> n;
		struct node *head = NULL;
		struct node *tail = NULL;
		for (int i = 0;i < n;i++) {
			cin >> tmp;
			insert(&head,&tail, tmp);
			printlist(head);
		}
	}
	return 0;
}
