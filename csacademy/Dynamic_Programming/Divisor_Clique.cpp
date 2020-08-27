#include <bits/stdc++.h>
using namespace std;
const int _max = 1e5 + 5;
typedef long long int lli;
#define endl "\n";
#define speed ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    vector<int> dp(n,1);
    int ans = 1;
    for(int i=1;i<n;i++){
        int current = arr[i];
        for(int j=i-1;j>=0;j--){
            if(current%arr[j]==0){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
        ans = max(dp[i],ans);
    }
    cout<<ans<<endl;
    return 0;
}
