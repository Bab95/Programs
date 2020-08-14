#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
bool solve(){
    int a,b;
    cin>>a>>b;
    int sum = 0;
    while(b){
        sum += b;
        b /= 2;
        if(sum>a){
            return true;
        }
    }
    if(sum>=a){
        return true;
    }
    return false;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        if(solve()){
            cout<<1<<endl;
        }else{
            cout<<0<<endl;
        }

    }
}
