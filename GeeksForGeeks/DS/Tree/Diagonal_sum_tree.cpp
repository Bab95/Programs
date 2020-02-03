#include <iostream>
#include <vector>
#include <map>
using namespace std;
struct node{
	int data;
	struct node *left,*right;
};
struct node *getnode(int data){
	struct node *tmp = (struct node *)malloc(sizeof(struct node));
	tmp->left = tmp->right = NULL;
	tmp->data = data;
	return tmp;
}
void diagonalSum(struct node *root,map<int,int>& my_map,int dist){
	if(root==NULL){
		return;
	}
	my_map[dist]+=root->data;
	diagonalSum(root->right,my_map,dist);
	diagonalSum(root->left,my_map,dist+1);
}
struct node *buildTree(){
	struct node *root = getnode(1);
	root->left = getnode(2);
	root->right = getnode(3);
	root->right->right = getnode(5);
	root->right->left = getnode(4);
	root->right->left->left = getnode(12);
	root->right->left->right = getnode(7);
	root->left->left = getnode(9);
	root->left->right = getnode(6);
	root->left->right->left = getnode(11);
	root->left->left->right = getnode(10);
	return root;
}
int main(){
	struct node *root = buildTree();
	map<int,int> my_map;
	diagonalSum(root,my_map,0);
	map<int,int>::iterator itr;
	for(itr=my_map.begin();itr!=my_map.end();itr++){
		cout<<itr->second<<endl;
	}
}
