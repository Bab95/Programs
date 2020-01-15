#include <iostream>
#include <limits.h>
void initalize(int arr[],int *first,int *second,int *third){
  if(arr[0]>arr[1]&&arr[0]>arr[2]){
    *first = arr[0];
    if(arr[1]>arr[2]){
      *second = arr[1];
      *third = arr[2];
      return;
    }else{
      *second = arr[2];
      *third = arr[1];
    }
  }else if(arr[1]>arr[2]){
    *first = arr[1];
    if(arr[0]>arr[2]){
      *second = arr[0];
      *third = arr[2];
    }else{
      *second = arr[2];
      *third = arr[0];
    }
  }
}
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
    int first = INT_MIN;
    int second = INT_MIN;
    int third = INT_MIN;
    initalize(arr,&first,&second,&third);
    for(int i=3;i<n;i++){
      if(arr[i]>first){
        third = second;
        second = first;
        first = arr[i];
      }else if(arr[i]>second){
        third = second;
        second = arr[i];
      }else if(arr[i]>third){
        third = arr[i];
      }
    }
    cout<<first<<" "<<second<<" "<<third<<endl;
  }
  return 0;
}
