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
int mod(int c){
    if(c<0){
        return -1*c;
    }
    return c;
}
int binarySearch(vector<int>& arr,int start,int end,int key){
    if(arr[end]<=key){
        return end;
    }
    if(key<=arr[start]){
        return start;
    }
    int mid = (start+end)/2;
    if(arr[mid]<=key&&arr[mid+1]>key){
        return mid;
    }else if(arr[mid]<key){
        return binarySearch(arr,mid+1,end,key);
    }
    return binarySearch(arr,start,mid-1,key);
}
void print(vector<int>& ans){
    fo(i,0,ans.size()-1){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
void solve(){
  int n;
  cin>>n;
  vector<int> arr(n);
  input(arr,n);
  int k,x;
  cin>>k>>x;
  int index = binarySearch(arr,0,n-1,x);
  int l,r;
  //cout<<index<<endl;
  if(x==arr[index]){
      l = index-1;
  }else{
      l = index;
  }
  r = index+1;
  int count = 0;
  vector<int> ans;
  while(l>=0&&r<=n-1&&count<k){
      if(x-arr[l]<=arr[r]-x){
        //cout<<arr[l]<<" ";
        ans.push_back(arr[l]);
        l--;
      }else{
        //cout<<arr[r]<<" ";
        ans.push_back(arr[r]);
        r++;
      }
      count++;
  }
  while(count<k&&l>=0){
      count++;
      //cout<<arr[l]<<" ";
      ans.push_back(arr[l]);
      l--;
  }
  while(count<k&&r<=n-1){
      //cout<<arr[r]<<" ";
      ans.push_back(arr[r]);
      r++;
      count++;
  }
  sort(ans.begin(),ans.end());
  print(ans);
  cout<<endl;
}
int main(){
  int t;
  cin>>t;
  while(t--){
    solve();
  }
  return 0;
}
