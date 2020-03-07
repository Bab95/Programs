#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#define MAX_SIZE 1000
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};
Node* insert(Node* head, int data)
{
	if (head == NULL)
		head = new Node(data);
	else
		head->next = insert(head->next, data);
	return head;
}
void removeTheLoop(Node *head);
void makeLoop(Node* head, int x)
{
	if (x == 0)
		return;
	Node* curr = head;
	Node* last = head;
	int counter = 0;
	while (counter < x)
	{
		curr = curr->next;
		counter++;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = curr;
}
int detectloop(Node* head)
{
	Node* hare = head->next;
	Node* tortoise = head;
	while (hare != tortoise && hare != NULL && tortoise != NULL)
	{
		hare = hare->next;
		tortoise = tortoise->next;
		if (hare != NULL && hare->next != NULL)
			hare = hare->next;
		if (hare == tortoise)
			return 1;
	}
	if (hare == tortoise)
		return 1;
	return 0;
}
int length(Node* head, bool hasloop)
{
	int len = 0;
	if (hasloop == false)
	{
		Node* temp = head;
		while (temp != NULL)
		{
			len++;
			temp = temp->next;
		}
		return len;
	}
	else
	{
		Node* hare = head->next;
		Node* tortoise = head;
		while (hare != tortoise)
		{
			hare = hare->next;
			tortoise = tortoise->next;
			hare = hare->next;
			if (hare == tortoise)
				break;
		}

		int looplen = 0;
		while (hare->next != tortoise)
		{
			hare = hare->next;
			looplen++;
		}

		looplen++;
		Node* begin = head;
		int startlen = 0;
		tortoise = tortoise->next;
		while (begin != tortoise)
		{

			begin = begin->next;
			tortoise = tortoise->next;
			startlen++;
		}

		return looplen + startlen;

	}
}
//Position this line where user code will be pasted.
int main() {
	int testcases;
	freopen("input.txt", "r", stdin);
	cin >> testcases;
	while (testcases--)
	{
		Node *head = NULL;
		int sizeOfArray;
		cin >> sizeOfArray;
		int arr[MAX_SIZE];
		for (int i = 0;i<sizeOfArray;i++)
		{
			cin >> arr[i];
			head = insert(head, arr[i]);

		}
		int x;
		cin >> x;
		makeLoop(head, x);
		int lengthll = 0;
		if (detectloop(head) == 1)
			lengthll = length(head, true);
		else
			lengthll = length(head, false);

		removeTheLoop(head);

		if (detectloop(head) == 0 && lengthll == length(head, false))
		{
			cout << 1 << endl;
		}
		else
			cout << 0 << endl;
	}
	return 0;
}
/*This is a function problem.You only need to complete the function given below*/

/*
struct Node {
int data;
struct Node *next;
Node(int x) {
data = x;
next = NULL;
}
};
*/
/*The function removes the loop from the linked list if present
You are required to complete this method*/
void printlist(Node *head) {
	Node *p = head;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
#include <map>
void removeTheLoop(Node *head)
{
	//Your code here
	/* Node *slow = head;
	Node *fast = head;
	Node *prev = NULL;
	while(slow!=fast){
	slow = slow->next;
	prev = fast->next;
	fast = fast->next->next;
	}
	if(slow==fast){
	cout<<"LOOP AND BREAK"<<endl;
	}
	slow = head;
	while(slow!=fast){
	prev = fast;
	fast = fast->next;
	slow = slow->next;
	}

	prev->next = NULL;

	*/
	map<Node*, bool> visited;
	Node *p = head;
	Node *prev = NULL;
	map<Node*, bool>::iterator itr;
	while (1) {
		if (p == NULL) {
			break;
		}
		itr = visited.find(p);
		if (itr == visited.end()) {
			//visited[p] = true;
			visited.insert(pair<Node*, bool>(p, true));
			prev = p;
			p = p->next;
		}
		else {
			break;
		}
	}
	//cout<<prev->data<<endl;
	if (prev) { prev->next = NULL; }
	//printlist(head);
}
