#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left, *right;

    Node(int x){
        int data = x;
        left = right = NULL;
    }
};
void swap( int* a, int* b )
{
    int t = *a;
    *a = *b;
    *b = t;
}
struct Node* NewNode(int data)
{
    struct Node* Node = (struct Node *)malloc(sizeof(struct Node));
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    return(Node);
}
struct Node *correctBST( struct Node* root );
void Inorder(struct Node *root){
	if(root==NULL){
		return;
	}
	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
}
int flag=1;
int c=0;
void inorder(struct Node *temp,struct Node *root){
	if(flag==0){
		return;
	}
	if(temp==NULL&&root==NULL)
		return;
	if(root==NULL){
		flag=0;
		return;
	}
	if(temp==NULL){
		flag=0;
		return;
	}
	if(temp->data==root->data){
	    c++;
	}
	inorder(temp->left,root->left);
	inorder(temp->right,root->right);
}
void insert(struct Node *root,int a1,int a2,char lr){
	if(root==NULL)
		return;
	if(root->data==a1){
		switch(lr){
				case 'L':root->left=NewNode(a2);
				break;
				case 'R':root->right=NewNode(a2);
				break;
			}
	}
	insert(root->left,a1,a2,lr);
	insert(root->right,a1,a2,lr);
}
int main()
{
	int t;
	cin>>t;
	while(t--){
	struct Node *root=NULL;
	struct Node *temp=NULL;
	int n;
	cin>>n;
	int m=n;
	while(n--){
		int a1,a2;
		char lr;
		cin>>a1>>a2>>lr;
		if(root==NULL){
			temp=NewNode(a1);
			root=NewNode(a1);
			switch(lr){
				case 'L':root->left=NewNode(a2);
				        temp->left=NewNode(a2);
				break;
				case 'R':root->right=NewNode(a2);
				        temp->right=NewNode(a2);
				break;
			}
		}
		else{
			insert(root,a1,a2,lr);
			insert(temp,a1,a2,lr);
		}
	}
	flag=1;
	c=0;

	root=correctBST(root);
	inorder(temp,root);
	if(c+1==m){
	    cout<<flag<<endl;
	}
	else{
	    cout<<"0
";
	}
	}
    return 0;
}

/*This is a function problem.You only need to complete the function given below*/

/*Complete the function
Node is as follows:
struct Node
{
    int data;
    struct Node *left, *right;

    Node(int x){
        int data = x;
        left = right = NULL;
    }
};
*/
#include <vector>
void inorder(struct Node* root,vector<Node*> &v){
    if(root==NULL){
        return;
    }
    inorder(root->left,v);
    v.push_back(root);
    inorder(root->right,v);
}
void swap_data(Node *a,Node *b){
    int tmp = a->data;
    a->data = b->data;
    b->data = tmp;
}
int partition(vector<Node*> &v,int start,int end){
    Node* pivot = v[start];
    int i = start+1;
    for(int j=start+1;j<=end;j++){
        if(v[j]->data<pivot->data){
            swap_data(v[i],v[j]);
            i++;
        }
    }
    swap_data(v[i-1],pivot);
    return i-1;
}
void quicksort(vector<Node*> &v,int start,int end){
    if(start<end){
        int pivot = partition(v,start,end);
        quicksort(v,start,pivot-1);
        quicksort(v,pivot+1,end);
    }
}
void pinorder(Node *root){
    if(root==NULL){
        return;
    }
    pinorder(root->left);
    cout<<root->data<<" ";
    pinorder(root->right);
}
struct Node *correctBST( struct Node* root )
{
    // add code here.
    vector<Node*> v;
    inorder(root,v);
    /*vector<Node*>::iterator itr;
    for(itr=v.begin();itr!=v.end();itr++){
        cout<<(*itr)->data<<" ";
    }*/
    quicksort(v,0,v.size()-1);
    //cout<<endl;
    //vector<Node*>::iterator itr;
    /*for(itr=v.begin();itr!=v.end();itr++){
        cout<<(*itr)->data<<" ";
    }
    cout<<endl;*/
    //pinorder(root);
    v.clear();
    return root;
}
