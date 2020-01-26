// { Driver Code Starts
#include<bits/stdc++.h>
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

void reversePrint(Node *root);

/* Driver program to test above functions*/
int main()
{
   int t;
  scanf("%d\n", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d\n",&n);
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

   reversePrint(root);
   cout<<endl;

  }
    return 0;
}


// } Driver Code Ends
/* A tree Node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
#include <queue>
#include <stack>
void reversePrint(Node *root)
{
    //Your code here
    queue<Node*> q;
    q.push(root);
    stack<int> s;
    Node *tmp;
    while(!q.empty()){
        tmp = q.front();
        q.pop();
        s.push(tmp->data);
        if(tmp->right){
            q.push(tmp->right);
        }
        if(tmp->left){
            q.push(tmp->left);
        }
    }
    int x;
    while(!s.empty()){
        x = s.top();
        s.pop();
        cout<<x<<" ";
    }
}
