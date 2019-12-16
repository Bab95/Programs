#include <iostream>
int max(int a,int b){
  return a>b?a:b;
}
int min(int a,int b){
  return a>b?b:a;
}
int main() {
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }
    int *left = new int[n];
    int *right = new int[n];
    left[0] = arr[0];
    for(int i=1;i<n;i++){
      left[i] = max(left[i-1],arr[i]);
    }
    right[n-1] = arr[n-1];
    for(int i=n-2;i>=0;i--){
      right[i] = max(right[i+1],arr[i]);
    }
    int water = 0;
    for(int i=0;i<n;i++){
      int tmp = min(left[i],right[i])-arr[i];
      water+=(tmp>=0)?tmp:0;
    }
    cout<<water<<endl;
  }
  return 0;
}
