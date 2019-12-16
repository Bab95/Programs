#include<bits/stdc++.h>
using namespace std;
struct node
{
	string data;
	struct node *left;
	struct node *right;

	node(string x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};
int evalTree(node *);
int main()
{
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
	string s[n];
	for(int i=0;i<n;i++)
		cin>>s[i];
	int p=0;
	node *root = new node(s[p]);
	queue<node *> q;
	q.push(root);
    p=1;
	while(!q.empty())
	{
		node *f = q.front();
		q.pop();
		node  *l,*r;
		if(p!=n){
        l=new node(s[p]);
		f->left = l;
		p++;
		q.push(l);
	    }
	    else
	    {
	    	f->left = NULL;
	    }
		if(p!=n){
        r=new node(s[p]);
		f->right = r;
		p++;
		q.push(r);
		}else
		{
			f->right=NULL;
		}
	}
	cout<<evalTree(root)<<endl;
    }
}

/*This is a function problem.You only need to complete the function given below*/
/*The structure of node is as follows
struct node{
	string data;
	node *left;
	node *right;
};
*/
/*You are required to complete below method */
#include <limits.h>
int convert2Int(string s){
    int ans = 0;
    for(int i=0;i<s.length();i++){
        int a = (int)s[i]-48;
        ans = ans*10+a;
    }
    return ans;
}
int calculate(int op1,int op2,string s){
    if(s[0]=='+'){
        return op1+op2;
    }
    if(s[0]=='-'){
        return op1-op2;
    }
    if(s[0]=='*'){
        return op1*op2;
    }
    if(s[0]=='/'){
        return op1/op2;
    }
    return INT_MIN;
}
int evalTree(node* root)
{
    //Your code here
    if(root->left==NULL&&root->right==NULL){
        int val = convert2Int(root->data);
        return val;
    }
    int op1 = evalTree(root->left);
    int op2 = evalTree(root->right);
    int ans = calculate(op1,op2,root->data);
    return ans;

}
