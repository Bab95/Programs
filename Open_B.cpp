#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ulli;
void solve(){
  string s = "codeforces";
  ulli n;
  cin>>n;
  int count = 0;
  while(n%2==0){
    n = n/2;
    count++;
  }
  vector<ulli> ans(10,(ulli)pow(2,count/10));
  int prev_count = 0;
  prev_count = count%10;
  if(prev_count!=0){
    for(int i=0;i<prev_count;++i){
      ans[i] *= 2;
    }
  }
    //cout<<"DEBUG:"<<prev_count<<endl;
  for(ulli i=3;i<=sqrt(n);i+=2){
    count = 0;
    while(n%i==0){
      count++;
      n = n/i;
    }
    if(count==0){
        continue;
    }
    int rem = 10-prev_count;
    cout<<"DEBUG: "<<rem<<endl;
    if(count>=rem){
      for(int j=prev_count;j<10;++j){
        ans[j]*=i;
      }
      count = count-rem;
      prev_count = 0;
      int p = count/10;
      prev_count = count%10;
      for(int j=0;j<10;++j){
        ans[j]*=(ulli)pow(i,p);
      }
      for(int k=0;k<prev_count;++k){
        ans[k]*=i;
      }
    }else{
        cout<<"DEBUG"<<"this"<<endl;
      for(int j=prev_count;j<prev_count+count;++j){
        ans[j]*=i;
      }
      prev_count = (prev_count+count)%10;
    }

  }
  if(n>2){
    //its a prime number.....
    cout<<"its a prime num"<<endl;
    ans[0] = n;
  }
  for(int i=0;i<10;++i){
      cout<<ans[i]<<" ";
  }
  cout<<endl;
  for(int i=0;s.length();++i){
    for(int j=0;j<ans[i];++j){
        cout<<s[i];
    }
  }
  cout<<endl;
}
int main(){
  solve();
}
