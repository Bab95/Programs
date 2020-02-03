// { Driver Code Starts
#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

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

bool printAncestors(struct Node *root, int target);

int main()
{
  int t;
  struct Node *child;
  scanf("%d\n", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d\n",&n);
     struct Node *root = NULL;
     if(n==1)
     {
        int a;
        cin>>a;
        cout<<a<<endl;
     }else{
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

        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     int a;
     cin>>a;
    printAncestors(root, a);
  }
  }
  return 0;
}
// } Driver Code Ends
/*
Structure of a node is as following
struct Node
{
     int data;
     struct Node* left;
     struct Node* right;
};
*/
// Function should print all the ancestor of the target node
bool findPath(struct Node *root,int target,vector<int> &path){
    if(root==NULL){
        return false;
    }
    path.push_back(root->data);
    if(root->data==target){
        return true;
    }
    if(findPath(root->left,target,path)||findPath(root->right,target,path)){
        return true;
    }
    path.pop_back();
    return false;
}
bool printAncestors(struct Node *root, int target)
{
     // Code here
     vector<int> path;
     bool b1 = findPath(root,target,path);
     if(b1){
         for(int i=path.size()-2;i>=0;i--){
             cout<<path[i]<<" ";
         }
         cout<<endl;
     }
     return b1;
}
