//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#define ALPHABETS 26
using namespace std;
struct node {
	struct node *child[ALPHABETS];
	bool isEnd;
};
struct node *getnode() {
	struct node *tmp = (struct node *)malloc(sizeof(struct node));
	for (int i = 0;i < ALPHABETS;i++) {
		tmp->child[i] = NULL;
	}
	tmp->isEnd = false;
	return tmp;
}
void insert(string s, struct node *root) {
	struct node *pcrawl = root;
	for (int i = 0;i < s.length();i++) {
		int index = (int)s[i] - 97;
		if (pcrawl->child[index] == NULL) {
			pcrawl->child[index] = getnode();
		}
		pcrawl = pcrawl->child[index];
	}
	pcrawl->isEnd = true;
}
bool search(string s, struct node *root) {
	struct node *pcrawl = root;
	for (int i = 0;i < s.length();i++) {
		int index = (int)s[i] - 97;
		if (pcrawl->child[index] == NULL) {
			return false;
		}
		pcrawl = pcrawl->child[index];
	}
	if (pcrawl != NULL&&pcrawl->isEnd == true) {
		return true;
	}
	return false;
}
int main() {
	int t,n;
	string s;
	//freopen("input.txt", "r", stdin);
	cin >> t;
	while (t--) {
		cin >> n;
		struct node *root = getnode();
		for (int i = 0;i < n;i++) {
			cin >> s;
			insert(s, root);
		}
		cin >> s;
		if (search(s, root)) {
			cout << "1" << endl;
		}
		else {
			cout << "0" << endl;
		}
	}
	return 0;
}
