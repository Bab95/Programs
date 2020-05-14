#include <bits/stdc++.h>
using namespace std;
int horizontal[101];
int vertical[101];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin>>n;
  vector<int> x(n);
  vector<int> y(n);
  memset(horizontal,0,sizeof(horizontal));
  memset(vertical,0,sizeof(vertical));
  for(int i=0;i<n;i++){
    cin>>x[i]>>y[i];
    horizontal[x[i]]++;
    vertical[y[i]]++;
  }
  int h=0,v=0;
  for(int i=0;i<101;++i){
    if(horizontal[i]>0){
      h++;
    }
    if(vertical[i]>0){
      v++;
    }
  }
  cout<<min(h,v)<<endl;
}
