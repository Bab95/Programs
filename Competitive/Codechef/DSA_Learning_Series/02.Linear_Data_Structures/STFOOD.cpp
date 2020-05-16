#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
#define fo(i,l,r) for(int i=l;i<=r;++i)
#define fi(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back
#define po pop_back
typedef long long int ll;
void input(vector<int>& arr,int n){
	fo(i,0,n-1){
		cin>>arr[i];
	}
}
void solve(){
	ll n;
	cin>>n;
	//ll s,p,v;
	vector<ll> s(n),p(n),v(n);
	ll profit = 0;
	fo(i,0,n-1){
		cin>>s[i]>>p[i]>>v[i];
		ll current_profit = ((ll)floor(p[i]/(s[i]+1)))*v[i];
		profit = max(current_profit,profit);
	}
	cout<<profit<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
