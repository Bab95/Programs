/*
Solution:Remove the balanced then count the unbalanced..
*/
#include <bits/stdc++.h>
using namespace std;
void solve(){
    string s;
    cin>>s;
    if(s.length()%2==1){
        cout<<-1<<endl;
        return;
    }
    stack<char> stk;
    for(int i=0;i<s.length();++i){
        if(stk.empty()){
            stk.push(s[i]);
        }else{
            if(stk.top()=='{'){
                if(s[i]=='}'){
                    stk.pop();
                }else{
                    stk.push(s[i]);
                }
            }else{
                //stk.top()=='}'
                stk.push(s[i]);
            }
        }
    }
    int open = 0;
    int close = 0;
    while(!stk.empty()){
        if(stk.top()=='{'){
            open++;
        }else{
            close++;
        }
        stk.pop();
    }
    cout<<((open+1)/2 + (close+1)/2)<<endl;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    solve();
	}
	return 0;
}
