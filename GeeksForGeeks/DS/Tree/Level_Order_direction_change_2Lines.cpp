#include <iostream>
#include <queue>
#include <stack>
using namespace std;
struct node{
  int data;
  struct node *left,*right;
};
struct node *getnode(int data){
  struct node *tmp = (struct node*)malloc(sizeof(struct node));
  tmp->data = data;
  tmp->left = NULL;
  tmp->right = NULL;
  return tmp;
}
void levelOrder(struct node *root){
  if(root==NULL){
    return;
  }
  if(root->left==NULL&&root->right==NULL){
    cout<<root->data<<endl;
    return;
  }
  //queue<pair<int,struct node*> > q;
  //pair<int,struct node *> p;
  //p.first = 0;
  //p.second = root;
  //q.push(p);
  bool right_to_left = false;
  //pair<int,struct node*> x;
  int level = 0;
  //stack<pair<int,struct node *> > s;
  queue<struct node*> q;
  stack<struct node*> s;
  q.push(root);
  while(!q.empty()){
    int size = q.size();
    level++;
    for(int i=0;i<size;i++){
      struct node  *tmp = q.front();
      q.pop();
      //cout<<tmp->data<<" ";
      if(right_to_left==false){
        cout<<tmp->data<<" ";
      }else{
        s.push(tmp);
      }
      if(tmp->left){
        q.push(tmp->left);
      }
      if(tmp->right){
        q.push(tmp->right);
      }
    }
    if(right_to_left==true){
      while(!s.empty()){
        struct node *tmp = s.top();
        s.pop();
        cout<<tmp->data<<" ";
      }
    }
    if(level==2){
      right_to_left = !right_to_left;
      level = 0;
    }
    cout<<endl;
  }
}
struct node *buildTree(){
  struct node *root = getnode(1);
  root->left = getnode(2);
  root->right = getnode(3);
  root->left->left = getnode(4);
  root->left->right = getnode(5);
  root->right->left = getnode(6);
  root->right->right = getnode(7);
  root->left->left->left = getnode(8);
  root->left->left->right = getnode(9);
  root->left->right->left = getnode(3);
  root->left->right->right = getnode(1);
  root->left->left->right->left = getnode(16);
  root->left->right->right->left = getnode(17);
  root->left->right->right->right = getnode(18);
  root->right->left->left = getnode(4);
  root->right->left->right = getnode(2);
  root->right->right->left = getnode(7);
  root->right->right->right = getnode(2);
  root->right->left->right->right = getnode(19);
  return root;
}
int main(){
  struct node *root = buildTree();
  levelOrder(root);
  return 0;
}
