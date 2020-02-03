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

void diagonalPrint(Node *root);

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
     diagonalPrint(root);
     cout<<endl;

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

#include <map>
#include <vector>
void diagonalPrintutil(Node *root,map<int,vector<Node*> > &my_map,int dist){
    if(root==NULL){
        return;
    }
    my_map[dist].push_back(root);
    diagonalPrintutil(root->left,my_map,dist+1);
    diagonalPrintutil(root->right,my_map,dist);
}
void diagonalPrint(Node *root)
{
   // your code here
   map<int,vector<Node*> > my_map;
   diagonalPrintutil(root,my_map,0);
   map<int,vector<Node*> >::iterator itr;
   for(itr=my_map.begin();itr!=my_map.end();itr++){
       for(int i=0;i<itr->second.size();i++){
           cout<<itr->second[i]->data<<" ";
       }
   }
}
