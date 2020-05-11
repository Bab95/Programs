#include <iostream>
#include <vector>
#include <string>
#include <string.h>
using namespace std;
#define fo(i,l,r) for(int i=l;i<=r;++i)
#define fi(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back
#define po pop_back
void solve(){
  int n;
  string nationality;
  cin>>n>>nationality;
  string title;
  int rank,score;
  int laddus = 0;
  for(int i=0;i<n;++i){
    cin>>title;
    if(title=="CONTEST_WON"){
      cin>>rank;
      laddus+=300;
      laddus+=max(0,20-rank);
      continue;
    }

    if(title=="TOP_CONTRIBUTOR"){
      laddus+=300;
      continue;
    }
    if(title=="CONTEST_HOSTED"){
      laddus+=50;
      continue;
    }
    if(title=="BUG_FOUND"){
      cin>>score;
      laddus+=score;
      continue;
    }
  }
  if(nationality[0]=='I'){
    cout<<laddus/200<<endl;
  }else{
    cout<<laddus/400<<endl;
  }
}
int main(){
  int t;
  cin>>t;
  while(t--){
    solve();
  }
  return 0;
}
