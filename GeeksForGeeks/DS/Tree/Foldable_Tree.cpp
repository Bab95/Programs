
#include <iostream>
using namespace std;
struct node{
	int data;
	struct node *left, *right;
};
struct node *getnode(int data){
	struct node *tmp = (struct node *)malloc(sizeof(struct node));
	tmp->data = data;
	tmp->left = tmp->right = NULL;
	return tmp;
}
bool foldableTree(struct node *r1,struct node *r2){
	if (r1 == NULL&&r2 == NULL){
		return true;
	}
	if ((r1 == NULL&&r1 != NULL) || (r1 != NULL&&r2 == NULL)){
		return false;
	}
	return foldableTree(r1->left, r2->right) && foldableTree(r1->right, r2->left);
}
struct node *buildTree(){
	struct node *root = getnode(10);
	root->left = getnode(7);
	root->right = getnode(15);
	root->left->right = getnode(9);
	root->left->left = getnode(18);
	root->right->left = getnode(11);
	return root;
}
int main(){
	struct node *root = buildTree();
	if (foldableTree(root, root)){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}
	return 0;
}
