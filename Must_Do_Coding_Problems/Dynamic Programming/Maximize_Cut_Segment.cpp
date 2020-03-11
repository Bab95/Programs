#include <iostream>
#include <string.h>
#define fori(i,l,r) for(int i=l;i<=r;i++)
using namespace std;
int max(int a,int b,int c){
    int t = a>b?a:b;
    return t>c?t:c;
}
void Print(int arr[],int n){
	fori(i,1,n-1){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main(){
  int t;
  int n;
  cin>>t;
  while(t--){
    cin>>n;
    int dp[n+1];
    memset(dp,-1,sizeof(dp));
    int x,y,z;
    int _x,_y,_z;
    cin>>x>>y>>z;
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        _x = ((i-x)>=0)?dp[i-x]:-1;
        _y = ((i-y)>=0)?dp[i-y]:-1;
        _z = ((i-z)>=0)?dp[i-z]:-1;
        if(_x!=-1||_y!=-1||_z!=-1){
            dp[i] = max(_x,_y,_z)+1;
        }
    }
    //Print(dp,n+1);
    cout<<dp[n]<<endl;
  }
  return 0;
}
