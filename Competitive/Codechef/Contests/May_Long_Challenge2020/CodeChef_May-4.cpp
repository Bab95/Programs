//Chef and Bitwise AND...
//CHANDF
#include <iostream>
#include <vector>
#define fo(i,l,r) for(int i=l;i<=r;++i)
#define fi(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back
#define po pop_back
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long int ll;
typedef unsigned long long int ulli;
using namespace std;
void solve(){

    ll x,y,l,r;
    cin>>x>>y>>l>>r;
    vector<ll> z;
    bool equal = true;
    ll current = 0;
    for(int i=62;i>=0;i--){
      ll p = (1LL<<i);
      if((l&p)==(r&p)&&equal){
        current+=(r&p);
        continue;
      }
      if(equal==true){
        equal = false;
        //we have found the first uneqal bit in L and R...
      }
      if(r&p){
        z.push_back(current+p-1);
        //not equal that kth bit zero rest ones making sure its greater
        //than L(as all the bits from k+1 to 41 is 1)
        //but smaller than R as kth bit is 1 in R then kth bit is zero in Z
      }
      current+=(r&p);
      //this will make sure that number is greater than L but smaller than and equal
      // to R....
    }
    z.push_back(r);
    z.push_back(l);
    sort(z.begin(),z.end());

    ll ans = z[0];
    //maximizing the function....
    for(ll z1:z){
        if(((x&z1)*(y&z1))>((x&ans)*(y&ans))){
            ans = z1;
        }
    }

    //now as we have to minimize the z value
    //if a particular bit is 0 in both x and y it should be
    //0 in z too so as to make sure it is minimum.....
    for(ll i=62;i>=0;i--){
      ll p = (1LL<<i);
      if((ans&p)==0){
        continue;
      }
      if(((x&p)==0)&&((y&p)==0)&&(ans-p)>=l){
        ans = ans-p;
      }
    }
    cout<<ans<<endl;
}
int main(){
    speed;
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
