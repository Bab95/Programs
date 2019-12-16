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
struct node* insert(int data,struct node *head) {
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
int bitonicpoint(struct node *head) {
	struct node *prev = head;
	struct node *current = head->next;
	while (current->next != NULL) {
		if ((current->data > prev->data) && (current->data > current->next->data)) {
			return current->data;
		}
		prev = current;
		current = current->next;
	}
	return -1;
}
int main() {
	int t, n;
	freopen("input.txt", "r", stdin);
	cin >> t;
	while (t--) {
		cin >> n;
		int tmp;
		struct node *head = NULL;
		for (int i = 0;i < n;i++) {
			cin >> tmp;
			head = insert(tmp,head);
		}
		printlist(head);
		cout << bitonicpoint(head)<<endl;
	}
	system("pause");
}
