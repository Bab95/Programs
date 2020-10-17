//
// Created by Babnish Vyas on 17/10/20.
//
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <stack>
using namespace std;
void solve(){
    string s;
    cin>>s;
    stack<char> stk;
    for(int i=0;i<s.length();++i){
        if(stk.empty()){
            stk.push(s[i]);
        }else{
            if(s[i]=='B'){
                stk.pop();
            }else{
                stk.push(s[i]);
            }
        }
    }
    cout<<stk.size()<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}