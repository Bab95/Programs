#include <iostream>
#include <string>
#include <strings.h>
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
int lcs(string& s1,string& s2,string& s3,int a,int b,int c){
    int dp[a+1][b+1][c+1];
    for(int i=0;i<=a;i++){
        for(int j=0;j<=b;j++){
            for(int k=0;k<=c;k++){
                if(i==0||j==0||k==0){
                    dp[i][j][k] = 0;
                }else if(s1[i-1]==s2[j-1]&&s1[i-1]==s3[k-1]){
                    dp[i][j][k] = dp[i-1][j-1][k-1]+1;
                }else{
                    dp[i][j][k] = max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));
                }
            }
        }
    }
    return dp[a][b][c];
}
int main(){
  int t;
  cin>>t;
  while(t--){
    string s1,s2,s3;
    int a,b,c;
    cin>>a>>b>>c;
    cin>>s1;
    cin>>s2;
    cin>>s3;
    cout<<lcs(s1,s2,s3,a,b,c)<<endl;
  }
  return 0;
}
