{
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
// A simple recursive function to convert a given Binary tree to Doubly
// Linked List
// root --> Root of Binary Tree
// head --> Pointer to head node of created doubly linked list
void bToDLL(Node *root, Node **head_ref);
/* Function to print nodes in a given doubly linked list */
void printList(Node *node)
{
    Node *prev = NULL;
    while (node!=NULL)
    {
        cout << node->data << " ";
        prev = node;
        node = node->right;
    }
    cout << endl;
    while (prev!=NULL)
    {
        cout << prev->data << " ";
        prev = prev->left;
    }
    cout << endl;
}
void inorder(Node *root)
{
   if (root != NULL)
   {
       inorder(root->left);
       cout << root->data;
       inorder(root->right);
   }
}
/* Driver program to test size function*/
int main()
{
  int t;
  cin >> t;

  while (t--)
  {
    map<int, Node*> m;
    int n;
    cin >> n;
    Node *root = NULL;

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
        Node *child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     Node *head = NULL;
     bToDLL(root, &head);
     printList(head);
  }
  return 0;
}

/*This is a function problem.You only need to complete the function given below*/

// This function should convert a given Binary tree to Doubly
// Linked List
#include <stack>
void bToDLL(Node *root, Node **head_ref)
{
    // your code here
    stack<Node*> s;
    Node *current = root;
    Node *q,*rightmp,*p;
    p = root;
    Node *resultNode = NULL;
    while(p!=NULL||!s.empty()){
        while(p!=NULL){
            s.push(p);
            p = p->left;
        }
        p = s.top();
        s.pop();
        rightmp = p->right;
        if(resultNode==NULL){
            resultNode = p;
            p->right = NULL;
            p->left = NULL;
            q = resultNode;
        }else{
            q->right = p;
            p->left = q;
            q = q->right;
            p->right = NULL;
        }
        p = rightmp;
    }
    *head_ref = resultNode;
}
