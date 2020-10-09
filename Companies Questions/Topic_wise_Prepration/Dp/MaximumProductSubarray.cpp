/*
at every point i max = {previous max*a[i],previous min * a[i],a[i]}
*/

#include <bits/stdc++.h>
using namespace std;
int maxProduct(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int> > dp(n,vector<int>(2,0));
    dp[0] = {nums[0],nums[0]};
    int ans = nums[0];
    for(int i=1;i<n;++i){
        dp[i][0] = max(dp[i-1][0]*nums[i],max(nums[i],dp[i-1][1]*nums[i]));
        dp[i][1] = min(dp[i-1][0]*nums[i],min(nums[i],dp[i-1][1]*nums[i]));
        ans = max(dp[i][0],ans);
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    cout<<maxProduct(arr);
}