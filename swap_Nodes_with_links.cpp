#include <iostream>
using namespace std;
struct node{
  int data;
  struct node *next;
};
struct node *getnode(int data){
  struct node *tmp = (struct node *)malloc(sizeof(struct node));
  tmp->data = data;
  tmp->next = NULL;
  return tmp;
}
struct node *insert(int data,struct node *root){
  if(root==NULL){
    return getnode(data);
  }
  struct node *tmp = getnode(data);
  struct node *p = root;
  while(p->next!=NULL){
    p = p->next;
  }
  p->next = tmp;
  return root;
}
int main(){
  int t;
  cin>>t;
  while(t--){
    int n,tmp;
    struct node *root = NULL;
    cin>>n;
    for(int i=0;i<n;i++){
      cin>>tmp;
      root = insert(tmp,root);
    }
    int x,y;
    cin>>x>>y;
    struct node *x_node = root;
    struct node *y_node = root;
    
  }
}
