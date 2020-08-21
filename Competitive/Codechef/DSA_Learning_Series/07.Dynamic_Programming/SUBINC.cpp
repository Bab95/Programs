#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    long int ans=0;
    long int count = 1;
    for(int i=0;i<n-1;++i){
        if(arr[i+1]>=arr[i]){
            count++;
        }else{
            ans += ((count*(count+1))/2);
            count = 1;
        }
    }
    ans += ((count*(count+1))/2);
    cout<<ans<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
