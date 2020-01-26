#include <iostream>
#include <queue>
using namespace std;
struct node{
  int data;
  struct node *left,*right;
};
struct node *getnode(int data){
  struct node *tmp = (struct node *)malloc(sizeof(struct node));
  tmp->data = data;
  tmp->left = tmp->right = NULL;
  return tmp;
}
void specificLevelOrder(struct node *root){
  if(root==NULL){
    return;
  }
  if(root->left==NULL){
    cout<<root->data<<endl;
    return;
  }
  if(root->left->left==NULL){
    cout<<root->data<<" "<<root->left->data<<" "<<root->right->data<<endl;
    return;
  }
  cout<<root->data<<" ";
  queue<struct node *> q;
  q.push(root->left);
  q.push(root->right);
  struct node *tmp1,*tmp2;
  while(!q.empty()){
    tmp1 = q.front();
    q.pop();
    tmp2 = q.front();
    q.pop();
    cout<<tmp1->data<<" ";
    cout<<tmp2->data<<" ";
    if(tmp1->left){
      q.push(tmp1->left);
    }
    if(tmp2->right){
      q.push(tmp2->right);
    }
    if(tmp1->right){
      q.push(tmp1->right);
    }
    if(tmp2->left){
      q.push(tmp2->left);
    }
  }
  cout<<endl;
}
struct node *buildTree(){
    struct node* root = getnode(1);

    root->left = getnode(2);
    root->right = getnode(3);
    root->left->left = getnode(4);
    root->left->right = getnode(5);
    root->right->left  = getnode(6);
    root->right->right = getnode(7);
    root->left->left->left  = getnode(8);
    root->left->left->right  = getnode(9);
    root->left->right->left  = getnode(10);
    root->left->right->right  = getnode(11);
    root->right->left->left  = getnode(12);
    root->right->left->right  = getnode(13);
    root->right->right->left  = getnode(14);
    root->right->right->right  = getnode(15);
    root->left->left->left->left  = getnode(16);
    root->left->left->left->right  = getnode(17);
    root->left->left->right->left  = getnode(18);
    root->left->left->right->right  = getnode(19);
    root->left->right->left->left  = getnode(20);
    root->left->right->left->right  = getnode(21);
    root->left->right->right->left  = getnode(22);
    root->left->right->right->right  = getnode(23);
    root->right->left->left->left  = getnode(24);
    root->right->left->left->right  = getnode(25);
    root->right->left->right->left  = getnode(26);
    root->right->left->right->right  = getnode(27);
    root->right->right->left->left  = getnode(28);
    root->right->right->left->right  = getnode(29);
    root->right->right->right->left  = getnode(30);
    root->right->right->right->right  = getnode(31);
    return root;
}
void inorder(struct node *root){
  if(root==NULL){
    return;
  }
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}
int main(){
  struct node *root = buildTree();
  inorder(root);
  cout<<endl;
  specificLevelOrder(root);
}
