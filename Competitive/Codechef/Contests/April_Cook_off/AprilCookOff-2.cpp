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
#include <string.h>
#include <math.h>
#define fo(i,l,r) for(int i=l;i<=r;++i)
#define fi(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back
#define po pop_back
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long int ll;
typedef unsigned long long int ulli;
#define M 1000000007
using namespace std;
void generatePrimes(){

}
void swap(int *a,int *b){
		int tmp = *a;
		*a = *b;
		*b = tmp;
}
void input(vector<int>& arr,int n){
		fo(i,0,n-1){
				cin>>arr[i];
		}
}
void input(vector<ll>& arr,int n){
	fo(i,0,n-1){
		cin>>arr[i];
	}
}
void input(vector<ulli>& arr,int n){
		fo(i,0,n-1){
				cin>>arr[i];
		}
}
ll max(ll a,ll b){
		return a>b?a:b;
}
ulli max(ulli a,ulli b){
		return a>b?a:b;
}
int max(int a,int b){
		return a>b?a:b;
}
void print(vector<int>& ans,int n){
		fo(i,0,n-1){
				cout<<ans[i]<<" ";
		}
		cout<<endl;
}
void print(vector<ulli>& ans,int n){
		fo(i,0,n-1){
				cout<<ans[i]<<" ";
		}
		cout<<endl;
}
ll power(ll x, ll y, ll p)
{
	ll res = 1;
	x = x % p;

	while (y > 0) {
		if (y & 1)
			res = (res * x) % p;

		y = y >> 1; // y = y/2
		x = (x * x) % p;
	}
	return res;
}
void solve(){
	ll n,a;
	cin>>n>>a;
	ulli ans = 0;
	ulli current = 1,prev = a;
	for(int i=1;i<=n;i++){
		current = power(prev,2*i-1,M);
		//cout<<"i: "<<i<<" "<<current<<endl;
		prev = (prev*current)%M;
		prev = prev%(M-1);
		ans = (ans+current)%M;
		current = 1;
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
