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

void levelOrder(struct Node* node);

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



int main()
{
    int t;cin>>t;while(t--){

        Node* head1 = make_tree();

        // inorder(head);
         levelOrder(head1);
         cout<<endl;
    }
    return 1;
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
  queue<pair<int,Node*> > q;
  pair<int,Node*> p;
  p.first = 0;
  p.second = node;
  int highest_level = 0;
  q.push(p);
  pair<int,Node*> x;
  while(!q.empty()){
      p = q.front();
      q.pop();
      if(p.first>highest_level){
          cout<<"$ ";
          highest_level = p.first;
      }
      cout<<p.second->data<<" ";
      if(p.second->left){
          x.first = p.first+1;
          x.second = p.second->left;
          q.push(x);
      }
      if(p.second->right){
          x.first = p.first+1;
          x.second = p.second->right;
          q.push(x);
      }
  }
  cout<<"$ ";
}
