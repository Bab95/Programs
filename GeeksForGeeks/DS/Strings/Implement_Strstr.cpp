#include<bits/stdc++.h>
using namespace std;
int strstr(string ,string);
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        string b;

        cin>>a;
        cin>>b;

        cout<<strstr(a,b)<<endl;
    }
}

/*This is a function problem.You only need to complete the function given below*/
/* The function should return position where the target string
   matches the string str
Your are required to complete this method */
int strstr(string s, string x)
{
     //Your code here
     int result = -1;
     for(int st=0;st<s.length();st++){
        if(x[0]==s[st]){
            int index = st;
            int j = 0;
            int k = st;
            while(x[j]!='\0'&&s[k]!='\0'){
                if(x[j]==s[k]){
                    j++;
                    k++;
                }else{
                    break;
                }
            }
            if(x[j]=='\0'){
                return st;
            }
        }
     }
     return -1;
}
