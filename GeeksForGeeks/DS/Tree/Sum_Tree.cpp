#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;

	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};
bool isSumTree(struct Node* node);
/* Computes the number of nodes in a tree. */
int height(struct Node* node)
{
  if (node==NULL)
    return 0;
  else
    return 1 + max(height(node->left), height(node->right));
}
void inorder(Node *root)
{
    if (root == NULL)
       return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d
", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     cout << isSumTree(root) << endl;
  }
  return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */
// Should return true if tree is Sum Tree, else false
#include <limits.h>
int sum(Node* root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL&&root->right==NULL){
        return root->data;
    }
    int left = sum(root->left);
    int right = sum(root->right);
    if(left+right!=root->data){
        return INT_MIN;
    }
    return left+right+root->data;
}
void myinorder(Node* root){
    if(root==NULL){
        return;
    }
    myinorder(root->left);
    cout<<root->data<<" ";
    myinorder(root->right);
}
bool isSumTree(Node* root)
{
     // Your code here
    // myinorder(root);
     //cout<<endl;
     if(root==NULL){
         return true;
     }
     int left = sum(root->left);
     int right = sum(root->right);
     if(left==INT_MIN||right==INT_MIN){
         return false;
     }
     if(left+right==root->data){
        return true;
     }
     return false;
}
