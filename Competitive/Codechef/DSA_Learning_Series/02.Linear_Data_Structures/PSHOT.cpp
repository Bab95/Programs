#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <unordered_map>
#include <map>
#include <limits.h>
#include <unordered_set>
#include <stack>
#include <string>
#include <math.h>
#define fo(i,l,r) for(int i=l;i<=r;++i)
#define fi(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back
#define po pop_back
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long int ll;
typedef unsigned long long int ulli;
using namespace std;
void solve(){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    int ahit=0,amiss=0,bhit=0,bmiss=0;
    for(int i=0;i<s.length();++i){
      if(i%2==0){
        if(s[i]=='1'){
          ahit++;
        }else{
          amiss++;
        }
      }else{
        if(s[i]=='1'){
          bhit++;
        }else{
          bmiss++;
        }
      }

      if((ahit+bmiss>n)||(bhit+amiss>n)){
        cout<<i+1<<endl;
        return;
      }
    }
    cout<<2*n<<endl;
}
int main(){
    speed;
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
