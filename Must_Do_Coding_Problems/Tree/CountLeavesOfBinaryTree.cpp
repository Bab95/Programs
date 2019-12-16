//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
int countLeaves(struct Node* root);
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
     scanf("%d
",&n);
     Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
      //  cout << n1 << " " << n2 << " " << (char)lr << endl;
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        Node *child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     cout << countLeaves(root) << endl;
  }
  return 0;
}
/*This is a function problem.You only need to complete the function given below*/
int countLeaves(Node* root)
{
  // Your code here
  if(root==NULL)
    return 0;
  if(root->left==NULL&&root->right==NULL){
      return 1;
  }
  int left = countLeaves(root->left);
  int right = countLeaves(root->right);
  return left+right;
}
