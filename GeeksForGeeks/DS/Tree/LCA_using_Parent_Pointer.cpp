#include <map>
#include <iostream>
using namespace std;
struct node{
  int data;
  struct node *left,*right,*parent;
};
struct node *getnode(int data){
  struct node *tmp = (struct node *)malloc(sizeof(struct node));
  tmp->parent = tmp->left = tmp->right = NULL;
  tmp->data = data;
  return tmp;
}
struct node *LCA(struct node *n1,struct node *n2){
  map<struct node *,bool> ancestors;
  while(n1!=NULL){
    ancestors[n1] = true;
    n1 = n1->parent;
  }
  while(n2!=NULL){
    if(ancestors.find(n2)!=ancestors.end()){
      return n2;
    }
    n2 = n2->parent;
  }
  return NULL;
}
struct node *insert(struct node *root,int data){
  if(root==NULL){
    return getnode(data);
  }
  if(root->data>data){
    root->left = insert(root->left,data);
    root->left->parent = root;
  }else{
    root->right = insert(root->right,data);
    root->right->parent = root;
  }
  return root;
}
int main(){
  struct node *root = NULL;
  int arr[] = {20,8,22,4,12,10,14};
  int n = sizeof(arr)/sizeof(arr[0]);
  for(int i=0;i<n;i++){
    root = insert(root,arr[i]);
  }
  struct node *n1 = root->left->right->left;
  struct node *n2 = root->left;
  struct node *lca = LCA(n1,n2);
  cout<<"LCA of "<<n1->data<<" & "<<n2->data<<" is "<<lca->data<<endl;
}
