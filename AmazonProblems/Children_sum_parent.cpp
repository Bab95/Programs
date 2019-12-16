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
void insert(Node *root,int a1,int a2,char lr){
	if(root==NULL){
		return;
	}
	if(root->data==a1){
		switch(lr){
			case 'L':root->left=new Node(a2);
			break;
			case 'R':root->right=new Node(a2);
			break;
		}
	}
	else{
		insert(root->left,a1,a2,lr);
		insert(root->right,a1,a2,lr);
	}
}
void inorder(Node *root){
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
int isSumProperty(Node *node);
int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	while(t-->0)
	{
		int n;
		cin>>n;
		int m=n;
		Node *root1=NULL;
		while(n-->0){
			int a1,a2;
			cin>>a1>>a2;
			char lr;
			scanf(" %c",&lr);
			if(root1==NULL){
				root1=new Node(a1);
				switch(lr){
					case 'L':root1->left=new Node(a2);
					break;
					case 'R':root1->right=new Node(a2);
					break;
				}
			}
			else{
				insert(root1,a1,a2,lr);
			}
		}
			cout<<isSumProperty(root1)<<endl;
	}
}

/*This is a function problem.You only need to complete the function given below*/
/*Complete the function below
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
#include<limits.h>
int isSumPropertyutil(Node *node)
{
 // Add your code here
    if(node==NULL){
        return 0;
    }
    if(node->left==NULL&&node->right==NULL){
        return node->data;
    }
    int left = isSumPropertyutil(node->left);
    int right = isSumPropertyutil(node->right);
    if(left+right==node->data){
        return node->data;
    }
    return INT_MAX;
}
int isSumProperty(Node *node){
    int left = isSumPropertyutil(node->left);
    int right = isSumPropertyutil(node->right);
    if(left+right==node->data){
        return 1;
    }
    return 0;
}
