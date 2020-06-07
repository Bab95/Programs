#include <bits/stdc++.h>
using namespace std;
void solve(){
  long long int n,d;
  cin>>n>>d;
  vector<long long int> arr(n);
  for(int i=0;i<n;++i){
    cin>>arr[i];
  }
  sort(arr.begin(),arr.end());
  int pairs = 0;
  for(int i=0;i<n;){
    if(i<n-1&&arr[i+1]-arr[i]<=d){
      pairs++;
      i+=2;
    }else{
      i+=1;
    }
  }
  cout<<pairs<<endl;
}
int main(){
  solve();
}
