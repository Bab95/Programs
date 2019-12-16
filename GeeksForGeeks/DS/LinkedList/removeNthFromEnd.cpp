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
struct node *removeNthFromEnd(struct node *head, int n) {
	struct node *p = head;
	struct node *q = head;
	struct node *prev = NULL;
	while (n--) {
		//prev = p;
		p = p->next;
	}
	while (p != NULL) {
		prev = q;
		p = p->next;
		q = q->next;
	}
	prev->next = q->next;
	free(q);
	return head;
}
int main() {
	int t, n, k;
	freopen("input.txt", "r", stdin);
	cin >> t;
	while (t--) {
		cin >> k >> n;
		int tmp;
		struct node *head = NULL;
		for (int i = 0;i < k;i++) {
			cin >> tmp;
			head = insert(tmp, head);
		}
		printlist(head);
		head = removeNthFromEnd(head, n);
		printlist(head);
	}
	system("pause");
}
