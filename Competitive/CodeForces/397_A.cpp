#include <bits/stdc++.h>
using namespace std;
bool segment[101];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin>>n;
  vector<int> x(n);
  vector<int> y(n);
  memset(segment,false,sizeof(segment));
  for(int i=0;i<n;i++){
    cin>>x[i]>>y[i];
  }
  for(int i=1;i<n;i++){
    for(int j=x[i];j<y[i];j++){
      segment[j] = true;
    }
  }
  int length = 0;
  for(int i=x[0];i<y[0];i++){
    if(!segment[i]){
      ++length;
    }
  }
  cout<<length<<endl;
}