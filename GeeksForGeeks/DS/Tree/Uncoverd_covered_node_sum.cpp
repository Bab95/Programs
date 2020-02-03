#include <iostream>
using namespace std;
struct node{
	int data;
	struct node *left,*right;
	bool boundary;
};
struct node *getnode(int data){
	struct node *tmp = (struct node *)malloc(sizeof(struct node));
	tmp->left = tmp->right = NULL;
	tmp->data = data;
	tmp->boundary = false;
	return tmp;
}
void uncoveredLeftSum(struct node *root,int *sum){
	if(root==NULL){
		return;
	}
	if(root->left){
		root->boundary = true;
		*sum = *sum+root->data;
		uncoveredLeftSum(root->left,sum);
	}else{
		root->boundary = true;
		*sum = *sum+=root->data;
		uncoveredLeftSum(root->right,sum);
	}
	return;
}
void uncoveredRightSum(struct node *root,int *sum){
	if(root==NULL){
		return;
	}
	if(root->right){
		root->boundary = true;
		*sum = *sum+root->data;
		uncoveredRightSum(root->right,sum);
	}
	else{
		root->boundary = true;
		*sum = *sum+root->data;
		uncoveredRightSum(root->left,sum);
	}
	return;
}
void coveredSum(struct node *root,int *sum){
	if(root==NULL){
		return;
	}
	coveredSum(root->left,sum);
	if(root->boundary==false){
		*sum = *sum+root->data;
	coveredSum(root->right,sum);
}
int main(){
	struct node *root = getnode(9);
	root->left = getnode(4);
	root->right = getnode(17);
	root->left->left = getnode(3);
	root->left->right = getnode(6);
	root->left->right->left = getnode(5);
	root->left->right->right = getnode(7);
	root->right->right = getnode(22);
	root->right->right->left = getnode(20);
	int lsum = 0,rsum = 0,csum = 0;
	uncoveredLeftSum(root->left,&lsum);
	uncoveredRightSum(root->right,&rsum);
	int boundarySum = lsum+rsum+root->data;
  root->boundary = true;
	coveredSum(root,&csum);
	cout<<lsum<<" "<<rsum<<" "<<boundarySum<<" "<<csum<<endl;
	if(boundarySum==csum){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
}
