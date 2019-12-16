#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    struct Node* nextRight;
    Node(int x){
        data = x;
        left = right = NULL;
        nextRight = NULL;
    }
};
void connect(struct Node *p);
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
void printSpecial(Node *root)
{
   if (root == NULL)
     return;
   Node *node = root;
   while (node != NULL)
   {
      cout<<node->data<<" ";
      node = node->nextRight;
   }
   if (root->left)
     printSpecial(root->left);
   else
     printSpecial(root->right);
}
void inorder(Node *root)
{
    if (root == NULL)
       return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d
", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
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
     connect(root);
     printSpecial(root);
     cout<<endl;
     inorder(root);
     cout<<endl;
  }
  return 0;
}

#include <queue>
void connect(Node *n)
{
   // Your Code Here
   queue<pair<Node*,int> > qu;
   pair<Node*,int> p;
   p.first = n;
   p.second =0;
   int current = 0;
   qu.push(p);
   while(!qu.empty()){
       pair<Node*,int> t = qu.front();
       qu.pop();
       if(!qu.empty()&&t.second==qu.front().second){
           t.first->nextRight = qu.front().first;
           qu.front().first->nextRight = NULL;
       }else{
           t.first->nextRight = NULL;
       }
       if(t.first->left){
           p.first = t.first->left;
           p.second = t.second+1;
           qu.push(p);
       }
       if(t.first->right){
           p.first = t.first->right;
           p.second = t.second+1;
           qu.push(p);
       }
   }
   /*queue<Node*> q1,q2;
   q1.push(p);
   Node *t;
   while(!q1.empty()||!q2.empty()){
       t = q1.front();
       q1.pop();
       while(!q1.empty()){

       }
   }*/
}
