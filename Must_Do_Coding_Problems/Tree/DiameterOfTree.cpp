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
        left = right = NULL;
    }
};
/* Function to get diameter of a binary tree */
int diameter(struct Node * tree);
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
     cout << diameter(root) << endl;
  }
  return 0;
}
/* Computes the diameter of binary tree with given root.  */
int max(int a,int b){
    return a>b?a:b;
}
int Height(Node* node){
    if(node==NULL)
        return 0;
    int left = Height(node->left);
    int right = Height(node->right);
    return max(left,right)+1;
}
int diameter(Node* node)
{
   // Your code here
   if(node==NULL){
       return 0;
   }
   int leftdiameter = diameter(node->left);
   int rightdiameter = diameter(node->right);

   int leftheight = Height(node->left);
   int rightheight = Height(node->right);

   return max(leftheight+rightheight+1,max(leftdiameter,rightdiameter));
}
