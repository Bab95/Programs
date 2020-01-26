// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

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


void printSpiral(struct Node *root);

/* Driver program to test above functions*/
int main()
{
   int t;
    cin >> t;
    while (t--) {
        int n, i, k;
        cin >> n;
        i = n;

        Node *root = NULL;
        queue<Node *> q;
        while (i > 0) {
            int a, b;
            char c;
            cin >> a >> b >> c;
            if (!root) {
                root = new Node(a);
                q.push(root);
            }
            Node *pick = q.front();
            q.pop();

            if (c == 'L') {
                pick->left = new Node(b);
                q.push(pick->left);
            }
            cin >> a >> b >> c;
            if (c == 'R') {
                pick->right = new Node(b);
                q.push(pick->right);
            }
            i -= 2;
        }
        printSpiral(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */
#include <queue>
#include <stack>
void printSpiral(Node *root)
{
    //Your code here
    queue<pair<int,Node*> > q;
    stack<pair<int,Node*> > s;
    pair<int,Node*> p;
    p.first = 0;
    p.second = root;
    q.push(p);
    pair<int,Node*> x;
    while(!q.empty()){
    while(!q.empty()){
        p = q.front();
        q.pop();
        cout<<p.second->data<<" ";
        if(p.first%2==0){
            x.first = p.first+1;
            if(p.second->right){
                x.second = p.second->right;
                s.push(x);
            }
            if(p.second->left){
                x.second = p.second->left;
                s.push(x);
            }
        }else{
            x.first = p.first+1;
            if(p.second->left){
                x.second = p.second->left;
                s.push(x);
            }
            if(p.second->right){
                x.second = p.second->right;
                s.push(x);
            }
        }
    }
    while(!s.empty()){
        p = s.top();
        s.pop();
        q.push(p);
    }

    }
}
