#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* right;
    Node* left;

    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
Node *insert(Node *root,int data)
{
    if(root==NULL)
    root=new Node(data);
    else if(data<root->data)
    root->left=insert(root->left,data);
    else
    root->right=insert(root->right,data);

    return root;
}
//Position this line where user code will be pasted.
int main() {

    int testcases;
    cin>>testcases;
    while(testcases--)
    {
        Node *root=NULL;
        int sizeOfArray;
        cin>>sizeOfArray;
        int arr[sizeOfArray];

        for(int i=0;i<sizeOfArray;i++)
        cin>>arr[i];

        for(int i=0;i<sizeOfArray;i++)
        {
            root=insert(root,arr[i]);
        }
        int l,h;
        cin>>l>>h;
        cout<<getCountOfNode(root,l,h)<<endl;


    }
	return 0;
}
}
/*This is a function problem.You only need to complete the function given below*/
/*
The structure of a BST node is as follows:
struct Node {
    int data;
    Node* right;
    Node* left;

    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
*/
void my_inorder(Node *root,int *count,int l,int h){
    if(root==NULL){
        return;
    }
    if(root->data>h){
        my_inorder(root->left,count,l,h);
    }
    if(root->data<l){
        my_inorder(root->right,count,l,h);
    }
    if(root->data<=h&&root->data>=l){
        *count = *count + 1;
        my_inorder(root->left,count,l,h);
        my_inorder(root->right,count,l,h);
    }
    return;
}
int getCountOfNode(Node *root, int l, int h)
{
  // your code goes here
  int count = 0;
  my_inorder(root,&count,l,h);
  return count;
}
