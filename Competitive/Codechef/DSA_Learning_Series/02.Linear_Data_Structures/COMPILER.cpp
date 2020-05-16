#include <iostream>
#include <vector>
#include <string>
#include <stack>
#define fo(i,l,r) for(int i=l;i<=r;++i)
#define fi(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back
#define po pop_back
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long int ll;
typedef unsigned long long int ulli;
using namespace std;
ll min(ll a,ll b){
    return a<b?a:b;
}
void solve(){
    string s;
    cin>>s;
    int ans = -1;
    int open = 0;
    for(int i=0;i<s.length();++i){
      if(s[i]=='<'){
        open++;
      }else{
        open--;
      }
      if(open==0){
        ans = i;
      }
      if(open<0){
        break;
      }
    }
    cout<<ans+1<<endl;
}
int main(){
    speed;
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
