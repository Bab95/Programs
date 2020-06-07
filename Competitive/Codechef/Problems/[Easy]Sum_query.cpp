#include <bits/stdc++.h>
using namespace std;
void solve(){
    long long int n,q;
    cin>>n>>q;
    vector<long long int> queries(q);
    for(long long int i=0;i<q;++i){
        cin>>queries[i];
    }
    for(int i=0;i<q;++i){
        //cout<<"query#"<<i+1<<" ";
        if(queries[i]<=n+1){
            cout<<0<<endl;
        }else if(queries[i]>2*n){
            long long int tmp = queries[i] - 2*n;
            long long int ans = n-tmp+1;
            cout<<ans<<endl;
        }else if(queries[i]>n&&queries[i]<=2*n){
            long long int ans = queries[i] - (n+1);
            cout<<ans<<endl;
        }else{
            cout<<0<<endl;
        }
    }
}
int main(){
    solve();
}
