#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#define MAX_SIZE 1024
using namespace std;
vector<int> tree[MAX_SIZE];
vector<int> centroidTree[MAX_SIZE];
bool centroidMarked[MAX_SIZE];
void addEdge(int u, int v) {
	tree[u].push_back(v);
	tree[v].push_back(u);
}
void DFS(int src, bool visited[], int subtree_size[], int *n) {
	visited[src] = true;
	*n = *n + 1;
	subtree_size[src] = 1;
	vector<int>::iterator itr;
	for (itr = tree[src].begin();itr != tree[src].end();itr++) {
		if (!visited[*itr] && !centroidMarked[*itr]) {
			DFS(*itr, visited, subtree_size, n);
			subtree_size[src] += subtree_size[*itr];
		}
	}
}
int getCentroid(int src, bool visited[], int subtree_size[], int n) {
	bool isCentroid = true;
	visited[src] = true;
	int heaviest_child = 0;
	vector<int>::iterator itr;
	for (itr = tree[src].begin();itr != tree[src].end();itr++) {
		if (!visited[*itr] && !centroidMarked[*itr]) {
			if (subtree_size[*itr] > n / 2) {
				isCentroid = false;
			}

			if (heaviest_child == 0 || subtree_size[*itr] > subtree_size[heaviest_child]) {
				heaviest_child = *itr;
			}
		}
	}

	if (isCentroid&&n - subtree_size[src] <= n / 2) {
		return src;
	}
	return getCentroid(heaviest_child, visited, subtree_size, n);
}
int findCentroid(int src) {
	bool visited[MAX_SIZE];
	int subtree_size[MAX_SIZE];
	memset(visited, false, sizeof(visited));
	memset(subtree_size, 0, sizeof(subtree_size));
	int n = 0;
	DFS(src, visited, subtree_size, &n);
	for (int i = 1;i < MAX_SIZE;i++) {
		visited[i] = false;
	}
	/*for (int i = 1;i <= n;i++) {
		cout << "subtree size of " << i << " " << subtree_size[i] << endl;
	}*/
	int centroid = getCentroid(src, visited, subtree_size, n);
	centroidMarked[centroid] = true;
	return centroid;
}
int decomposeTree(int root) {
	int centroid = findCentroid(root);
	cout << centroid << " ";
	vector<int>::iterator itr;
	for (itr = tree[centroid].begin();itr != tree[centroid].end();itr++) {
		if (!centroidMarked[*itr]) {
			int centroidSubtree = decomposeTree(*itr);
			centroidTree[centroid].push_back(centroidSubtree);
			centroidTree[centroidSubtree].push_back(centroid);
		}
	}
	return centroid;
}
int main() {
	int e;
	freopen("input.txt", "r", stdin);
	cin >> e;
	int u, v;
	for (int i = 0;i < e;i++) {
		cin >> u >> v;
		addEdge(u, v);
	}
	int centroidRoot = decomposeTree(1);
	cout << endl << centroidRoot << endl;
	return 0;
}
