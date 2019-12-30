#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
struct Qnode {
	int pageNumber;
	struct Qnode *prev;
	struct Qnode *next;
};
struct Queue {
	int count;
	int numberOfFrames;
	struct Qnode *front, *rear;
};
struct Hash {
	int capacity;
	Qnode **array;
};
struct Qnode *getQnode(int pageNumber) {
	struct Qnode *tmp = (struct Qnode*)malloc(sizeof(Qnode));
	tmp->pageNumber = pageNumber;
	tmp->prev = NULL;
	tmp->next = NULL;
	return tmp;
}
struct Queue* createQueue(int noOfFrames) {
	struct Queue* queue = (struct Queue*)malloc(sizeof(Queue));
	queue->count = 0;
	queue->numberOfFrames = noOfFrames;
	queue->front = NULL;
	queue->rear = NULL;
	return queue;
}
struct Hash* createHash(int capacity) {
	struct Hash* hash = (struct Hash*)malloc(sizeof(Hash));
	hash->capacity = capacity;
	hash->array = (struct Qnode**)malloc(sizeof(Qnode)*hash->capacity);
	for (int i = 0;i < hash->capacity;i++) {
		hash->array[i] = NULL;
	}
	return hash;
}
bool isQueueEmpty(Queue *queue) {
	if (queue->rear == NULL) {
		return true;
	}
	return false;
}
bool areAllFramesFull(struct Queue *queue) {
	if (queue->count == queue->numberOfFrames) {
		return true;
	}
	return false;
}
void delete_queue(struct Queue *queue) {
	if (isQueueEmpty(queue)) {
		return;
	}
	if (queue->front == queue->rear) {
		queue->front = NULL;
	}
	Qnode *tmp = queue->rear;
	queue->rear = queue->rear->prev;
	if (queue->rear) {
		queue->rear->next = NULL;
	}
	free(tmp);
	queue->count--;
}
void insert_queue(struct Queue *queue, struct Hash *hash, int pageNumber) {
	if (areAllFramesFull(queue)) {
		hash->array[queue->rear->pageNumber] = NULL;
		delete_queue(queue);
	}
	struct Qnode *tmp = getQnode(pageNumber);
	tmp->next = queue->front;
	if (isQueueEmpty(queue)) {
		queue->rear = tmp;
		queue->front = tmp;
	}
	else {
		queue->front->prev = tmp;
		queue->front = tmp;
	}
	hash->array[pageNumber] = tmp;
	queue->count++;
}
void referencePage(struct Queue *queue, struct Hash *hash, int pageNumber) {
	struct Qnode *reqPage = hash->array[pageNumber];
	if (reqPage == NULL) {
		insert_queue(queue, hash, pageNumber);
	}
	else if(reqPage!=queue->front) {
		reqPage->prev->next = reqPage->next;
		if (reqPage->next) {
			reqPage->next->prev = reqPage->prev;
		}
		if (reqPage == queue->rear) {
			queue->rear = reqPage->prev;
			queue->rear->next = NULL;
		}
		reqPage->next = queue->front;
		reqPage->prev = NULL;
		reqPage->next->prev = reqPage;
		queue->front = reqPage;
	}
}
void PrintQueue(struct Queue *queue) {
	struct Qnode *p = NULL;
	for (p = queue->front;p != queue->rear;p = p->next) {
		cout << p->pageNumber << " ";
	}
	/*if (p == queue->front&&p == queue->rear) {
		cout << p->pageNumber;
	}*/

	cout <<queue->rear->pageNumber<< endl;
	return;
}
int main() {
	//Cache size == QueueSize
	struct Queue *queue = createQueue(4);
	//Hash Capacity == NoOf Pages Refered
	struct Hash *hash = createHash(10);

	//1,2,3,1,4,5
	referencePage(queue, hash, 1);
	PrintQueue(queue);
	referencePage(queue, hash, 2);
	PrintQueue(queue);
	referencePage(queue, hash, 3);
	PrintQueue(queue);
	referencePage(queue, hash, 1);
	PrintQueue(queue);
	referencePage(queue, hash, 4);
	PrintQueue(queue);
	referencePage(queue, hash, 5);
	PrintQueue(queue);
	system("pause");
	return 0;
}
