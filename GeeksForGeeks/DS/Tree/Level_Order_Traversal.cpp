// { Driver Code Starts
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

void levelOrder(struct Node* node);

/* Helper function to test mirror(). Given a binary
   search tree, print out its data elements in
   increasing sorted order.*/
void inOrder(struct Node* node)
{
  if (node == NULL)
    return;

  inOrder(node->left);
  printf("%d ", node->data);

  inOrder(node->right);
}

// This finctions takes input and generates a tree corresponding to it
Node* make_tree()
{
	int n;
	cin>>n;

	Node* head=NULL;
	queue <Node*> q;

	for( ; n>0 ; n-=2 )
	{
		int a,b;
		char c;
		cin>> a >> b >> c;

        if(!head)
		{
			head = new Node(a);
			q.push(head);
		}

        Node* pick = q.front();
		q.pop();

		if(c == 'L')
		{
			pick->left = new Node(b);
			q.push( pick->left );
		}

		cin>> a >> b >> c;

		if(c == 'R')
		{
			pick->right = new Node(b);
			q.push( pick->right );
		}
	}
	return head;
}

/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d\n", &t);
  while (t--)
  {
      Node* head = make_tree();
      levelOrder(head);
      cout << endl;
  }
  return 0;
}


// } Driver Code Ends
/* A binary tree Node

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
 */

//You are required to complete this method
#include <queue>
void levelOrder(Node* node)
{
  //Your code here
  queue<Node*> q;
  q.push(node);
  while(q.empty()==false){
      Node* tmp = q.front();
      q.pop();
      cout<<tmp->data<<" ";
      if(tmp->left!=NULL){
          q.push(tmp->left);
      }
      if(tmp->right!=NULL){
          q.push(tmp->right);
      }
  }
  //cout<<endl;
}
