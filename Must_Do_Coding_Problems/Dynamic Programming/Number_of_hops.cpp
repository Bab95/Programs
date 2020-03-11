#include <iostream>
using namespace std;
void print(int arr[],int n){
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}
int min(int a,int b){
    return a<b?a:b;
}
int max(int a,int b){
    return a>b?a:b;
}
int main(){
  int t;
  cin>>t;
  int n;
  while(t--){
    cin>>n;
    int dp[n+1];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3;i<=n;i++){
        dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
    }
    cout<<dp[n]<<endl;
  }
  return 0;
}
