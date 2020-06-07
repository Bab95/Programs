#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    int g = gcd(arr[0],arr[1]);
    for(int i=2;i<n;++i){
        g = gcd(g,arr[i]);
    }
    cout<<g<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
//gcd(a,b) = gcd(a-b,b);
