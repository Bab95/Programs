// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 501

int getId(int M[MAX][MAX],int n);

int main()
{
    int T;
    cin>>T;
    int M[MAX][MAX];
    while(T--)
    {
        int N;
        cin>>N;
        memset(M,0,sizeof M);
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cin>>M[i][j];
            }
        }
        cout<<getId(M,N)<<endl;

    }
}

// } Driver Code Ends
// The task is to complete this function

// M[][]: input matrix
// n: size of matrix (n*n)
#include <stack>
int getId(int knows[MAX][MAX], int n)
{
    //Your code here
    stack<int> s;
    for(int i=0;i<n;i++){
        s.push(i);
    }
    int a = s.top();
    s.pop();
    int b = s.top();
    s.pop();
    if(s.empty()){
        if(knows[0][1]&&!knows[1][0]){
            return 1;
        }else if(knows[1][0]&&!knows[0][1]){
            return 0;
        }else{
            return -1;
        }
    }
    while(s.size()>1){
        if(knows[a][b]){
            a = s.top();
            s.pop();
        }else{
            b = s.top();
            s.pop();
        }
    }
    int c = s.top();
    s.pop();
    if(knows[c][b]){
        c = b;
    }
    if(knows[c][a]){
        c = a;
    }
    bool celebrity = true;
    for(int i=0;i<n;i++){
        if((i!=c)&&(knows[c][i]||!knows[i][c])){
            return -1;
        }
    }
    return c;
}
