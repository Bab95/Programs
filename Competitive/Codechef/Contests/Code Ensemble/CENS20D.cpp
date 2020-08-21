#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ulli;
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    if(n==1){
        cout<<0<<endl;
        return;
    }
    int count = 0;
    for(int i=0;i<n-1;++i){
        for(int j=i+1;j<n;++j){
            int tmp = arr[i]&arr[j];
            if(tmp==arr[i]){
                count++;
            }
        }
    }
    cout<<count<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}