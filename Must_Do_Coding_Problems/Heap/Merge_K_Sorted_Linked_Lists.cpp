struct compare {
	bool operator()(const pair<int, pair<int, Node* > > p1, const pair<int, pair<int, Node* > > p2) {
		return p1.first > p2.first;
	}
};
Node * mergeKLists(Node *arr[], int N)
{
	// Your code here
	priority_queue<pair<int, pair<int, Node *> >, vector<pair<int, pair<int, Node*> > >, compare > pq;
	for (int i = 0;i<N;i++) {
		//pair<int,Node*> p;
		pair<int, pair<int, Node *> > p;
		p.first = arr[i]->data;
		Node *tmp = arr[i];
		arr[i] = arr[i]->next;
		tmp->next = NULL;
		p.second.second = tmp;
		p.second.first = i;
		//arr[i] = arr[i]->next;
		pq.push(p);
	}
	Node *result = NULL;
	Node *q = NULL;

	while (!pq.empty()) {
		pair<int, pair<int, Node *> > p = pq.top();
		pq.pop();
		if (result == NULL) {
			result = p.second.second;
			q = result;
		}
		else {
			q->next = p.second.second;
			q = q->next;
		}
		int index = p.second.first;
		//arr[index] = arr[index]->next;
		if (arr[index] == NULL) {
			continue;
		}
		else {
			p.first = arr[index]->data;
			p.second.first = index;
			Node *tmp = arr[index];
			arr[index] = arr[index]->next;
			tmp->next = NULL;
			p.second.second = tmp;
			pq.push(p);
		}
	}
	if (q != NULL) {
		q->next = NULL;
	}
	return result;

}
