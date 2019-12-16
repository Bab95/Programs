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
void verticalOrder(Node *root);
/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d
", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d
",&n);
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
     verticalOrder(root);
     cout << endl;
  }
  return 0;
}

/*This is a function problem.You only need to complete the function given below*/

 #include<map>
 #include<queue>
 #include<vector>
void verticalOrder(Node *root)
{
    //Your code here
    map<int,vector<Node *> > m;
    queue<pair<int,Node*> > q;
    pair<int,Node*> p;
    p.first = 0;
    p.second = root;
    q.push(p);
    while(!q.empty()){
        pair<int,Node*> t = q.front();
        q.pop();
        m[t.first].push_back(t.second);
        if(t.second->left){
            p.first = t.first-1;
            p.second = t.second->left;
            q.push(p);
        }
        if(t.second->right){
            p.first = t.first+1;
            p.second = t.second->right;
            q.push(p);
        }
    }
    map<int,vector<Node*> >::iterator itr;
    vector<Node*>::iterator jtr;
    for(itr=m.begin();itr!=m.end();itr++){
        for(jtr=itr->second.begin();jtr!=itr->second.end();jtr++){
            cout<<(*jtr)->data<<" ";
        }
    }
    m.clear();
}
