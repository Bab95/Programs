
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
/*This is a function problem.You only need to complete the function given below*/
/*
Structure of the node of the tree is as
struct Node
{
	int key;
	struct Node* left, *right;
};
*/
// complete this function
// return true/false if the is Symmetric or not
bool isSymmetrical(struct Node* r1,struct Node* r2){
    if(r1==NULL&&r2==NULL){
        return true;
    }
    if(r1==NULL||r2==NULL){
        return false;
    }
    if(r1->key==r2->key){
        return isSymmetrical(r1->left,r2->right)&&isSymmetrical(r1->right,r2->left);
    }
    return false;
}
bool isSymmetric(struct Node* root)
{
	// Code here
	return isSymmetrical(root,root);
}
