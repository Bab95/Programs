#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    int ans = 0;
    int current = 0;
    for(int i=0;i<n;){
        if(arr[i]!=0){
            ++current;
            ++i;
        }else{
            ans = max(current,ans);
            current = 0;
            ++i;
        }
    }
    ans = max(ans,current);
    cout<<ans<<endl;
}
int main(){
    int t;
    solve();
}
