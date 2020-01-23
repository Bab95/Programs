#include<bits/stdc++.h>
using namespace std;

struct et
{
	char value;
	et* left, *right;

	et(char x){
	    value = x;
	    left = right = NULL;
	}
};

bool isOperator(char c)
{
	if (c == '+' || c == '-' ||
			c == '*' || c == '/' ||
			c == '^')
		return true;
	return false;
}

void inorder(et *t)
{
	if(t)
	{
		inorder(t->left);
		printf("%c ", t->value);
		inorder(t->right);
	}
}

et* constructTree(char []);

int main()
{
    int t;
    cin>>t;
    while(t--){
    char postfix[25];
	cin>>postfix;
	et* r = constructTree(postfix);
	inorder(r);
	cout<<endl;
}
return 0;
}// } Driver Code Ends
/*struct et
{
	char value;
	et* left, *right;
};*/

//function to construct expression tree
#include <stack>
struct et* getnode(char c){
    struct et* tmp = new et(c);
    //tmp->value = c;
    tmp->left = tmp->right = NULL;
    return tmp;
}
et* constructTree(char postfix[])
{
//code here
    stack<et*> s;
    struct et *n1;
    struct et *n2;
    for(int i=0;postfix[i]!='\0';i++){
        if(postfix[i]=='+'||postfix[i]=='-'||postfix[i]=='*'||postfix[i]=='/'||postfix[i]=='^'){
            if(!s.empty()){
                n2 = s.top();
                s.pop();
            }
            if(!s.empty()){
                n1 = s.top();
                s.pop();
            }
            struct et *tmp = getnode(postfix[i]);
            tmp->left = n1;
            tmp->right = n2;
            s.push(tmp);
        }else{
            struct et *tmp = getnode(postfix[i]);
            s.push(tmp);
        }
    }
    struct et *result = s.top();
    return result;
}
