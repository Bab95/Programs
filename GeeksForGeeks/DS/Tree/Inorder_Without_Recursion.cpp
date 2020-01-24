#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct node{
  int data;
  struct node *left,*right;
};
struct node *getnode(int data){
  struct node *tmp = (struct node *)malloc(sizeof(struct node));
  tmp->data = data;
  tmp->left = NULL;
  tmp->right = NULL;
  return tmp;
}
vector<int> inorder(struct node *root){
  vector<int> result;
  struct node *current = root;
  stack<struct node*> s;
  while(!s.empty()||curren!=NULL){
    while(current!=NULL){
      s.push(current);
      current = current->left;
    }
    current = s.top();
    s.pop();
    result.push_back(current->data);
    current = current->right;
  }
  return result;
}
struct node *buildtree(){
  struct node *root = getnode(1);
  root->left = getnode(2);
  root->right = getnode(3);
  root->left->left = getnode(4);
  root->left->right = getnode(5);
  root->right->left = getnode(6);
  root->right->right = getnode(7);
  return root;
}
int main(){
  struct node *root = buildtree();
  vector<int> result = inorder(root);
  for(int i=0;i<result.size();i++){
    cout<<result[i]<<" ";
  }
  cout<<endl;
}
