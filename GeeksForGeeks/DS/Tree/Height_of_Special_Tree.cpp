// { Driver Code Starts
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

void saveLeafNodes(Node* root, vector<Node*> &leaf)
{
    if(!root)return;
    saveLeafNodes(root->left, leaf);
    if(root->left==NULL && root->right==NULL)leaf.push_back(root);
    saveLeafNodes(root->right, leaf);
}

void linkLeafNodes(Node* root)
{
    vector<Node*> leaf;
    saveLeafNodes(root, leaf);
    if(leaf.size()<=1)return;
    for(int i=0; i<leaf.size(); i++)
    {
        if(i==0)
        {
            leaf[i]->right=leaf[i+1];
            leaf[i]->left=leaf[leaf.size()-1];
        }
        else if(i==leaf.size()-1)
        {
            leaf[i]->right=leaf[0];
            leaf[i]->left=leaf[i-1];
        }
        else
        {
            leaf[i]->right=leaf[i+1];
            leaf[i]->left=leaf[i-1];
        }
    }
    return;
}

int findTreeHeight(Node* node);

/* Driver program to test size function*/
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
     linkLeafNodes(root);
     cout<<findTreeHeight(root)<<endl;
  }
  return 0;
}// } Driver Code Ends
/*Structure of the node of the binary tree
struct Node
{
	int key;
	Node* left, *right;
};
*/
// function should return the height of the binary tree
int max(int a,int b){
    return a>b?a:b;
}
int findTreeHeight(Node* root)
{
	// Code here
	if(root==NULL){
	    return 0;
	}
	if(root->right!=NULL&&root->right->left==root){
	    return 1;
	}
	int left = findTreeHeight(root->left);
	int right = findTreeHeight(root->right);
	return max(left,right)+1;
}
