#include <bits/stdc++.h>
using namespace std;
int segment[101];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin>>n;
  vector<int> x(n);
  vector<int> y(n);
  memset(segment,0,sizeof(segment));
  for(int i=0;i<n;i++){
    cin>>x[i]>>y[i];
  }
  int a = x[0];
  int b = y[0];
  for(int i=1;i<n;i++){
    if(y[i]<=a||x[i]>=b){
      continue;
    }else{
      for(int j=max(x[i],a);j<min(y[i],1+b);j++){
        segment[j]++;
      }
    }
  }
  int length = 0;
  for(int i=a;i<=b;i++){
    if(segment[i]==0){
    	//cout<<i<<" ";
      length++;
    }
  }
  //cout<<endl;
  cout<<length<<endl;

}
