//Code by 1shubhamjoshi1
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
void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }
    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }
}
void inorderrrrr(Node *root)
{
    if(root!=NULL)
    {
    inorderrrrr(root->left);
    cout<<root->data<< " ";
    inorderrrrr(root->right);
    }
}
void modify(Node **root);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;
        root = NULL;
        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);
        }
        modify(&root);
        inorderrrrr(root);
        cout<<endl;
    }
}
/*This is a function problem.You only need to complete the function given below*/
/* BST Node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */
/*  modifies the root of the bst */
#include <stack>
#include <queue>
void inorder_my(struct Node *root,stack<Node *> &s){
    if(root==NULL){
        return;
    }
    inorder_my(root->left,s);
    s.push(root);
    inorder_my(root->right,s);
}
void modify(Node **root)
{
// Your code here
    stack<Node *> s;
    inorder_my(*root,s);
    queue<int> q;
    q.push(0);
    while(!s.empty()&&!q.empty()){
        Node *tmp = s.top();
        s.pop();
        tmp->data = tmp->data+q.front();
        q.pop();
        q.push(tmp->data);
    }
}
