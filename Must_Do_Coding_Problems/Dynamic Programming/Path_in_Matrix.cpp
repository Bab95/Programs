#include <iostream>
using namespace std;
void print(int arr[],int n){
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
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
    int matrix[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
    /*for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }*/
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            int _x = (j>0)?matrix[i-1][j-1]:0;
            int _y = matrix[i-1][j];
            int _z = (j<n-1)?(matrix[i-1][j+1]):0;
            matrix[i][j] += max(_x,max(_y,_z));
        }
    }
    int ans = matrix[n-1][0];
    for(int i=0;i<n;i++){
        ans = max(ans,matrix[n-1][i]);
    }
    cout<<ans<<endl;
  }
  return 0;
}
