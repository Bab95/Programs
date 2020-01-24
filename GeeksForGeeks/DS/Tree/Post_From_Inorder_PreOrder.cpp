#include <iostream>
using namespace std;
struct node{
    int data;
    struct node *left, *right;
};
struct node *getnode(int data){
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->data = data;
    return tmp;
}
int findIndex(int arr[],int val,int n){

}
void printPostOrder(int [],int pre[],int n){

}
int main() {
	//code
	return 0;
}
