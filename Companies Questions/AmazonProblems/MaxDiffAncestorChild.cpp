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
int maxDiff(Node *root);
int main()
{
  int t;
  struct Node *child;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
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
    cout<<maxDiff(root)<<endl;
 }
  return 0;
}
/* Your are required to 
complete this method*/
#include <limits.h>
int max(int a,int b){
    return a>b?a:b;
}
int min(int a,int b){
    return a<b?a:b;
}
int diff(Node* root,int &result){
    if(root==NULL){
        return INT_MAX;
    }
    if(root->left==NULL&&root->right==NULL){
        return root->data;
    }
    int l = diff(root->left,result);
    int r = diff(root->right,result);
    int m = min(l,r);
    result = max(result,(root->data)-m);
    return min(m,root->data);
}
int maxDiff(Node* root)
{
    int result = INT_MIN;
    diff(root,result);
    return result;
}
