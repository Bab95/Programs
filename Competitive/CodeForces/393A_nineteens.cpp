#include <bits/stdc++.h>
using namespace std;
int min(int a,int b){
	return a<b?a:b;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin>>s;
  int arr[4];
  memset(arr,0,sizeof(arr));
  for(int i=0;i<s.length();i++){
    if(s[i]=='n'){
      ++arr[0];
    }else if(s[i]=='i'){
      ++arr[1];
    }else if(s[i]=='e'){
      ++arr[2];
    }else if(s[i]=='t'){
      ++arr[3];
    }
  }
  int ans = arr[1];
  ans = min(ans,arr[3]);
  ans = min(ans,arr[2]/3);
  ans = min(ans,(arr[0]-1)/2);
  cout<<ans<<endl;
  return 0;
}
