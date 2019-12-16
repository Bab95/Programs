// C++ Program to print Bottom View of Binary Tree
#include<bits/stdc++.h>
using namespace std;
// Tree node class
struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references
    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
};
// Method that prints the bottom view.
void bottomView(Node *root);
/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d
", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d
",&n);
     struct Node *root = NULL;
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
     bottomView(root);
     cout << endl;
  }
  return 0;
}

#include <map>
map<int,Node*> m;
void Bview(Node *root,int hd){
    if(root==NULL){
        return;
    }
    m[hd] = root;
    Bview(root->left,hd-1);
    Bview(root->right,hd+1);
}
void bottomView(Node *root)
{

    Bview(root,0);
    map<int,Node*>::iterator itr;
    for(itr=m.begin();itr!=m.end();itr++){
        cout<<itr->second->data<<" ";
    }
    //cout<<endl;
    m.clear();
   // Your Code Here
}
