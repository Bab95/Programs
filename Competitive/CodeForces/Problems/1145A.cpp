#include <iostream>
using namespace std;
bool isSorted(int arr[],int start,int end){
  for(int i=start;i<=end-1;i++){
    if(arr[i]>arr[i+1]){
      return false;
    }
  }
  return true;
}
int max(int a,int b){
    return a>b?a:b;
}
int longestSort(int arr[],int start,int end){
  if(start>end){
      return 1;
  }
  if(start==end){
    return 1;
  }
  if(isSorted(arr,start,end)){
    return end-start+1;
  }
  int mid = start+(end-start)/2;
  int left = longestSort(arr,start,mid);
  int right = longestSort(arr,mid+1,end);
  return max(left,right);
}
int main(){
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  int res = longestSort(arr,0,n-1);
  cout<<res<<endl;
}
