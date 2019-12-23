
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <limits.h>
#include <iostream>
using namespace std;
#define MAX_SIZE 100000
struct ListNode {
	int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

struct node{
	ListNode* pointer;
	int data;
	int listno;
};

struct node heap[MAX_SIZE];
bool heap_empty(int *psize);
void swap(struct node* h1, struct node* h2);
void copy(struct node *h1, struct node *h2);
void insert_heap(struct node heap[], int *psize, ListNode* l2, int listno);
struct node delete_heapnode(struct node heap[], int *psize);
void restoredown(struct node heap[], int i, int heapsize);
void restoreup(struct node heap[], int heap_size);
void buildLists(vector<ListNode*> &lists, vector<vector<int> > &data, vector<int> &sizes);
ListNode* getnode(int data);
void printlist(ListNode* p);
ListNode* mergeKLists(vector<ListNode*>& lists) {
	heap[0].data = INT_MIN;
	heap[0].listno = -1;
	heap[0].pointer = NULL;
	int n = lists.size();
	ListNode* result = NULL;
	ListNode* q = NULL;
	int heap_size = 1;
	for (int i = 0; i<n; i++){
		insert_heap(heap, &heap_size, lists[i], i);
		lists[i] = lists[i]->next;
	}
	struct node tmp;
	while (!heap_empty(&heap_size)){
		tmp = delete_heapnode(heap, &heap_size);
		if (result == NULL){
			result = tmp.pointer;
			q = result;
		}
		else{
			q->next = tmp.pointer;
			q = q->next;
			q->next = NULL;
		}
		int lno = tmp.listno;
		if (lists[lno] != NULL){
			insert_heap(heap, &heap_size, lists[lno], lno);
			lists[lno] = lists[lno]->next;
		}
	}
	return result;
}
bool heap_empty(int *psize){
	if (*psize <= 1){
		return true;
	}
	return false;
}
void swap(struct node* h1, struct node* h2){
	int a, b;
	ListNode* tmp;
	a = h1->data;
	b = h1->listno;
	tmp = h1->pointer;
	h1->data = h2->data;
	h1->listno = h2->listno;
	h1->pointer = h2->pointer;
	h2->data = a;
	h2->listno = b;
	h2->pointer = tmp;
	return;
}
void copy(struct node *h1, struct node *h2){
	h1->data = h2->data;
	h1->listno = h2->listno;
	h1->pointer = h2->pointer;
	return;
}
void insert_heap(struct node heap[], int *psize, ListNode* l2, int listno){
	int heap_size = *psize;
	heap[heap_size].pointer = l2;
	heap[heap_size].data = l2->val;
	heap[heap_size].listno = listno;
	heap_size++;
	*psize = heap_size;
	restoreup(heap, heap_size - 1);
	return;
}

void restoreup(struct node heap[], int heap_size){
	int i = heap_size;
	int par = i / 2;
	int k = heap[i].data;
	struct node tmp_node;
	copy(&tmp_node, &heap[i]);
	while (heap[par].data>k){
		copy(&heap[i], &heap[par]);
		i = par;
		par = i / 2;
	}
	copy(&heap[i], &tmp_node);
	return;
}
struct node delete_heapnode(struct node heap[], int *psize){
	if (*psize <= 1){
		return heap[0];
	}
	swap(&heap[1], &heap[*psize - 1]);
	*psize = *psize - 1;
	restoredown(heap, 1, *psize-1);
	return heap[*psize];
}
void restoredown(struct node heap[], int i, int heapsize){
	int left = 2 * i;
	int right = 2 * i + 1;
	struct node tmp_node;
	copy(&tmp_node, &heap[i]);
	while (right <= heapsize){
		if (tmp_node.data <= heap[left].data&&tmp_node.data <= heap[right].data){
			copy(&heap[i], &tmp_node);
			return;
		}
		else if (heap[left].data<heap[right].data){
			copy(&heap[i], &heap[left]);
			i = left;
		}
		else{
			copy(&heap[i], &heap[right]);
			i = right;
		}
		left = 2 * i;
		right = 2 * i + 1;
	}
	if (left == heapsize&&tmp_node.data>heap[left].data){
		copy(&heap[i], &heap[left]);
		i = left;
	}
	copy(&heap[i], &tmp_node);
	return;
}
ListNode* getnode(int data){
	ListNode* tmp = (ListNode*)malloc(sizeof(ListNode));
	tmp->val = data;
	tmp->next = NULL;
	return tmp;
}
void buildLists(vector<ListNode*> &lists, vector<vector<int> > &data, vector<int> &sizes){
	ListNode* q = NULL;
	for (int i = 0; i < sizes.size(); i++){
		q = NULL;
		for (int j = 0; j < sizes[i]; j++){
			if (lists[i] == NULL){
				lists[i] = getnode(data[i][j]);
				q = lists[i];
			}
			else{
				q->next = getnode(data[i][j]);
				q = q->next;
			}
		}
	}
}
void printlist(ListNode* p){
	while (p != NULL){
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}
int main(){
	int t;
	freopen("input.txt", "r", stdin);
	cin >> t;
	int n_lists;
	while (t--){
		cin >> n_lists;
		vector<ListNode*> lists(n_lists,NULL);
		vector<vector<int> > data;
		vector<int> tmp;
		for (int i = 0; i < n_lists; i++){
			data.push_back(tmp);
		}
		vector<int> sizes(n_lists);
		for (int i = 0; i < n_lists; i++){
			cin >> sizes[i];
		}
		int input;
		for (int i = 0; i < n_lists; i++){
			for (int j = 0; j < sizes[i]; j++){
				cin >> input;
				data[i].push_back(input);
			}
		}
		buildLists(lists, data,sizes);

		ListNode* result = mergeKLists(lists);
		printlist(result);
	}
}
