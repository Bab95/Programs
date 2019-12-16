#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
struct node {
	int data;
	struct node *next,*prev;
};
struct node *getnode(int data) {
	struct node *tmp = (struct node *)malloc(sizeof(struct node));
	tmp->next = NULL;
	tmp->prev = NULL;
	tmp->data = data;
	return tmp;
}
struct node* insert(int data, struct node *head) {
	if (head == NULL) {
		return getnode(data);
	}
	struct node *p = getnode(data);
	p->next = head;
	p->prev = NULL;
	head->prev = p;
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
struct node *dll2BST(struct node *head) {
	if (head == NULL||head->next==NULL) {
		return head;
	}
	struct node *slow, *fast;
	slow = head;
	fast = head;
	struct node *prev = NULL;
	while (fast!=NULL&&fast->next != NULL) {
		prev = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	prev->next = NULL;
	struct node *q = slow->next;
	if (q != NULL) {
		q->prev = NULL;
	}
	slow->next = NULL;
	slow->prev = NULL;
	slow->prev = dll2BST(head);
	slow->next = dll2BST(q);
	return slow;

}
void inorder(struct node *root) {
	if (root == NULL) {
		return;
	}
	inorder(root->prev);
	cout << root->data << " ";
	inorder(root->next);
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
			head = insert(tmp, head);
		}
		printlist(head);
		head = dll2BST(head);
		inorder(head);
		cout << endl;
	}
	system("pause");
}
