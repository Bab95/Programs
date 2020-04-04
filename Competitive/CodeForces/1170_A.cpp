#include <bits/stdc++.h>
using namespace std;
int main(){
    int q;
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        if(a==b){
            cout<<a-1<<" 1 "<<"1"<<endl;
        }else{
            int middle = min(a,b)-1;
            int largest = max(a,b)-middle;
            cout<<max(largest,middle)<<" "<<min(largest,middle)<<" "<<1<<endl;
        }
    }
}