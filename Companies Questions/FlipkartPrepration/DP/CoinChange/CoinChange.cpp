/*No of ways to change amount int coins*/
#include <bits/stdc++.h>
using namespace std;
int find_solution(vector<int>& coins,int n,int sum){
    if(sum==0){
        return 1;
    }
    if(sum<0){
        return 0;
    }
    if(n<0&&sum>0){
        return 0;
    }
    return find_solution(coins,n,sum-coins[n]) + find_solution(coins,n-1,sum);
}
/*No of ways to change coins*/
int coinChangeDp(vector<int>& coins,int sum){
    int n = coins.size();
    vector<vector<int> > dp(n+1,vector<int>(sum+1,0));
    for(int i=1;i<=n;++i){
        dp[i][0] = 1;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=sum;++j){
            int include = 0;
            if(coins[i-1]<=j){
                include = dp[i][j-coins[i-1]];
            }
            int exclude = 0;
            exclude = dp[i-1][j];
            dp[i][j] = include + exclude;
        }
    }
    return dp[n][sum];
}
/*Variation:
Minimum no of coins 
*/
int minimum_coins(vector<int>& coins,int n,int sum){
    vector<vector<int> > dp(n+1,vector<int>(sum,INT_MAX));
    for(int i=0;i<=n;++i){
        dp[i][0] = 0;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=sum;++j){
            int include = INT_MAX;
            int exclude = INT_MAX;
            if(coins[i-1]<=j){
                include = (dp[i][j-coins[i-1]]==INT_MAX)?INT_MAX:(dp[i][j-coins[i-1]]+1);
            }
            exclude = dp[i-1][j];
            dp[i][j] = min(include,exclude);
        }
    }
    return dp[n][sum];
}
int main(){
    vector<int> coins;
    int sum,n;
    cin>>sum>>n;
    coins.assign(n,0);
    for(int i=0;i<n;++i){
        cin>>coins[i];
    }
    cout<<find_solution(coins,n-1,sum)<<endl;
}