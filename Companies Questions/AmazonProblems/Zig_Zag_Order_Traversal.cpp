//Initial Template for C++
#include <bits/stdc++.h>
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
void zigZagTraversal(Node* root);
int main()
{
  int t;
  cin>>t;
  while (t--)
  {
     map<int, Node*> m;
     int n;
     cin>>n;
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
     zigZagTraversal(root);
  }
  return 0;
}
// Contributed by: Hashit Sidhwa

/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
/*Structure of the node of the binary tree is as
struct Node {
	int data;
	struct Node *left, *right;
};
*/
// your task is to complete this function
// Function takes a single argument as input
// the root of the binary tree
// print a new line after each test case
#include <queue>
#include <stack>

void zigZagTraversal(Node* root)
{
	// Code here
    stack<Node*> current_level;
    stack<Node*> next_level;
    bool leftoright = true;
    current_level.push(root);
    while(!current_level.empty()){
        struct Node* node = current_level.top();
        current_level.pop();
        cout<<node->data<<" ";
        if(!leftoright){
            if(node->right){
               next_level.push(node->right);
            }
            if(node->left){
                next_level.push(node->left);
            }
        }else{
            if(node->left){
                next_level.push(node->left);
            }
            if(node->right){
                next_level.push(node->right);
            }
        }
        if(current_level.empty()){
            leftoright = !leftoright;
            swap(current_level,next_level);
        }
    }
    cout<<endl;
}
