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

void printBoundary(Node *root);

int height(struct Node *root)
{
    if(root==NULL)
        return 0;
    int l = 1+height(root->left);
    int r=1+height(root->right);
    if(l>r)
        return l;
    else
        return r;

}


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

    printBoundary(root);
   cout<<endl;

  }
    return 0;
}

// } Driver Code Ends
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */
void printLeaf(Node *root){
    if(root==NULL){
        return;
    }
    if(root->left==NULL&&root->right==NULL){
        cout<<root->data<<" ";
        return;
    }
    printLeaf(root->left);
    printLeaf(root->right);
}
void printLeftBoundary(Node *root){
    if(root==NULL){
        return;
    }
    if(root->left==NULL&&root->right==NULL){
        return;
    }
    cout<<root->data<<" ";
    if(root->left){
        printLeftBoundary(root->left);
    }else{
        printLeftBoundary(root->right);
    }
    return;
}
void printRightBoundary(Node *root){
    if(root==NULL){
        return;
    }
    if(root->left==NULL&&root->right==NULL){
        return;
    }
    if(root->right){
        printRightBoundary(root->right);
    }else{
        printRightBoundary(root->left);
    }
    cout<<root->data<<" ";
    return;
}
void printBoundary(Node *root)
{
     //Your code here
     if(root==NULL){
         return;
     }
     cout<<root->data<<" ";
     //if(root->left){
      printLeftBoundary(root->left);
     //}else{
       //  printLeftBoundary(root->right);
     //}
     printLeaf(root);
     //if(root->right){
      printRightBoundary(root->right);

     //}else{
         //printRightBoundary(root->left);
     //}
}
