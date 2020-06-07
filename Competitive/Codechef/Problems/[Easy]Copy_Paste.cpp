#include <bits/stdc++.h>
using namespace std;
void solve(){
  int n;
  cin>>n;
  unordered_map<int,int> mmap;
  int element;
  for(int i=0;i<n;++i){
    cin>>element;
    mmap[element]++;
  }
  cout<<mmap.size()<<endl;
}
int main(){
  int t;
  cin>>t;
  while(t--){
    solve();
  }
  return 0;
}
