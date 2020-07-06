#include <bits/stdc++.h>
using namespace std;
void solve(){
  int n,k;
  cin>>n>>k;
  vector<int> arr(n);
  for(int i=0;i<n;++i){
    cin>>arr[i];
  }
  sort(arr.begin(),arr.end(),greater<int>());
  int points = arr[k-1];
  if(points<=0){
    int ans = 0;
    while(arr[ans]>0&&ans<k){
      ans++;
    }
    cout<<0<<endl;
    return;
  }
  while(k<n&&arr[k]==points){
    k++;
  }
  cout<<k<<endl;
  return;
}
int main(){
  solve();
}
