
#include <iostream>
#include <limits.h>
using namespace std;
int main(){
  int t,n;
  cin>>t;
  while(t--){
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }
    int dp[n][n];
    for(int i=1;i<n;i++){
      dp[i][i] = 0;
    }
    for(int l=2;l<n;l++){
      for(int i=1;i<n-l+1;i++){
        int j = i+l-1;
        dp[i][j] = INT_MAX;
        for(int k=i;k<j-1;k++){
          int cost = dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j];
          if(q<mat[i][j]){
            mat[i][j] = cost;
          }
        }
      }
    }
    cout<<dp[1][n-1]<<endl;
  }
  return 0;
}
