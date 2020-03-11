#include <iostream>
#include <string.h>
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
    int arr[n];
    int dp1[n];
    int dp2[n];
    //memset(dp1,1,sizeof(dp1));
    //memset(dp2,1,sizeof(dp2));
    for(int i=0;i<n;i++){
        cin>>arr[i];
        dp1[i] = arr[i];
        dp2[i] = arr[i];
    }
    //print(dp1,n);
    //print(dp2,n);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]&&dp1[i]<dp1[j]+arr[i]){
                dp1[i] = dp1[j]+arr[i];
            }
        }
    }
    for(int i=n-2;i>=0;i--){
        for(int j=n-1;j>i;j--){
            if(arr[i]>arr[j]&&dp2[i]<dp2[j]+arr[i]){
                dp2[i] = dp2[j]+arr[i];
            }
        }
    }
     int res = dp1[0]+dp2[0]-arr[0];
    for(int i=1;i<n;i++){
        res = max(dp1[i]+dp2[i]-arr[i],res);
    }
    //print(dp1,n);
    //print(dp2,n);
    //cout<<dp1[n-1]<<" "<<dp2[n-1]<<endl;
    cout<<res<<endl;
  }
  return 0;
}
