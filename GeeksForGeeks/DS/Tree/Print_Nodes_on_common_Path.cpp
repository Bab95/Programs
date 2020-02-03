#include <vector>
#include <iostream>
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
bool findPath(struct node *root,int a,vector<int> &path){
	if(root==NULL){
		return false;
	}
	path.push_back(root->data);
	if(root->data==a){
		return true;
	}
	if(findPath(root->left,a,path)||findPath(root->right,a,path)){
		return true;
	}
	path.pop_back();
	return false;
}
void printCommonNodes(struct node *root,int a,int b){
	vector<int> v1,v2;
	bool b1 = findPath(root,a,v1);
	bool b2 = findPath(root,b,v2);
	for(int i=0;i<v1.size()&&i<v2.size();i++){
		if(v1[i]==v2[i]){
			cout<<v1[i]<<" ";
		}else{
			break;
		}
	}
	cout<<endl;
	return;
}
struct node *buildTree(){
		struct node* root = getnode(1);
		root->left = getnode(2);
		root->right = getnode(3);
		root->left->left = getnode(4);
		root->left->right = getnode(5);
		root->right->left = getnode(6);
		root->right->right = getnode(7);
		root->left->left->left = getnode(8);
		root->right->left->left = getnode(9);
		root->right->left->right = getnode(10);
		return root;
}
int main(){
	struct node *root = NULL;
	root = buildTree();
	printCommonNodes(root,9,7);
}
