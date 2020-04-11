#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <list>
#include <string.h>
using namespace std;
#define fo(i,l,r) for(int i=l;i<=r;i++)
#define fi(i,r,l) for(int i=r;i>=l;i--)
#define pb push_back
#define po pop_back
#define INF 1e9+9
void input(vector<int>& arr,int n){
  fo(i,0,n-1){
    cin>>arr[i];
  }
}
int findPivot(vector<int>& arr,int start,int end){
    if(start>end){
        return -1;
    }
    int mid = (start+end)/2;
    if(mid<end&&arr[mid]>arr[mid+1]){
        return mid+1;
    }
    if(mid>start&&arr[mid]<arr[mid-1]){
        return mid;
    }
    
    if(arr[mid]>arr[start]){
        return findPivot(arr,mid+1,end);
    }
    return findPivot(arr,start,mid-1);
}
void solve(){
  int n;
  cin>>n;
  vector<int> arr(n);
  input(arr,n);
  int ans = findPivot(arr,0,n-1);
  //cout<<ans<<endl;
  if(ans!=-1){
      cout<<arr[ans]<<endl;
  }else{
      cout<<arr[0]<<endl;
  }
}
int main(){
  int t;
  cin>>t;
  while(t--){
    solve();
  }
  return 0;
}
