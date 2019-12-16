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
void preorder(struct node *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
struct node *bst(int arr[],int start,int end){
    if(start<=end){
        int mid = start+(end-start)/2;
        struct node *root = getnode(arr[mid]);
        root->left = bst(arr,start,mid-1);
        root->right = bst(arr,mid+1,end);
        return root;
    }
    return NULL;
}
void solve(int arr[],int n){
    struct node *root = NULL;
	root = bst(arr,0,n-1);
	preorder(root);
	cout<<endl;
}
int main() {
	//code
	int t;
	cin>>t;
	int n;
	while(t--){
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    solve(arr,n);
	}
	return 0;
}
