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
void insert(struct node **head, int data) {
	struct node *p = getnode(data);
	if (*head == NULL) {
		*head = p;
		p->next = (*head);
		p->prev = (*head);
		return;
	}
	//IN the begining....
	if (p->data < (*head)->data) {
		p->next = (*head);
		p->prev = (*head)->prev;
		(*head)->prev = p;
		p->prev->next = p;
		(*head) = p;
		return;
	}
	//At the end....
	if (p->data > (*head)->prev->data) {
		(*head)->prev->next = p;
		p->prev = (*head)->prev;
		(*head)->prev = p;
		p->next = (*head);
		return;
	}
	struct node *tmp = *head;
	while (tmp->data < p->data) {
		tmp = tmp->next;
	}
	p->next = tmp;
	p->prev = tmp->prev;
	p->prev->next = p;
	tmp->prev = p;
	return;
}
void printlist(struct node *head) {
	struct node *p = head;
	while (p->next != head) {
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
			insert(&head, tmp);
			printlist(head);
		}
		printlist(head);
	}
	return 0;
}
