// { Driver Code Starts
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

int findDist(Node* ,int ,int );


/* Driver program to test size function*/
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
     int a,b;
     cin>>a>>b;

     cout<<findDist(root,a,b)<<endl;

  }
  }
  return 0;
}
// } Driver Code Ends
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

/* Should return minimum distance between a and b
   in a tree with given root*/
#include <vector>
bool findPath(Node* root,int a,vector<int> &v){
    if(root==NULL){
        return false;
    }
    v.push_back(root->data);
    if(root->data==a){
        return true;
    }
    if(findPath(root->left,a,v)||findPath(root->right,a,v)){
        return true;
    }
    v.pop_back();
    return false;
}
int findDist(Node* root, int a, int b)
{
    // Your code here
    vector<int> p1,p2;
    bool b1 = findPath(root,a,p1);
    bool b2 = findPath(root,b,p2);
    int i = 0;
    int dist = 0;
    if(b1&&b2){
        for(i=0;i<p1.size()&&i<p2.size();i++){
            if(p1[i]!=p2[i]){
                break;
            }
        }
        dist = p1.size()-(i);
        dist+=p2.size()-(i);
    }
    return dist;
}
