#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool isSubsequence(string& s1,string& s2){
  int m = s1.length();
  int n = s2.length();
  if(m>n){
    return isSubsequence(s2,s1);
  }
  int j = 0;
  for(int i=0;i<n;++i){
    if(j<m&&s1[j]==s2[i]){
      j++;
    }
    if(j==m){
        break;
    }
  }
  if(j==m){
    return true;
  }
  return false;
}
void solve(){
  string m,w;
  cin>>m;
  cin>>w;
  if(isSubsequence(m,w)){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }
}
int main(){
  int t;
  cin>>t;
  while(t--){
    solve();
  }
}
