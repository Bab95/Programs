#include <bits/stdc++.h>
using namespace std;
void solve(){
    long long int t;
    cin>>t;
    if(t%2==1){
        cout<<t/2<<endl;
    }else{
        int p2 = 0;
        long long int tmp = t;
        while(t%2==0){
            t = t/2;
            ++p2;
        }
        //p2 has power of 2 in tom's number
        //so we need all the numbers which are less than
        //t but has power of 2 greater than p2;
        cout<<t/2<<endl;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
