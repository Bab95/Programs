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
using namespace std;
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
void print(vector<ll>& ans,int n){
		fo(i,0,n-1){
				cout<<ans[i]<<" ";
		}
		cout<<endl;
}
bool sign(ll a){
	if(a>0){
		return true;
	}
	return false;
}
void solve(){
		ll n;
		cin>>n;
		vector<ll> arr(n);
		input(arr,n);
		vector<ll> brr;
		int i = 0;
		while(i<n){
			if(i<n&&sign(arr[i])==true){
				//positive find max in +ve region....
				ll tmp = arr[i];
				while(i<n&&sign(arr[i])==true){
					tmp = max(arr[i],tmp);
					++i;
				}
				brr.pb(tmp);
			}
			if(i<n&&sign(arr[i])==false){
				ll tmp = arr[i];
				while(i<n&&sign(arr[i])==false){
					tmp = max(arr[i],tmp);
					++i;
				}
				brr.pb(tmp);
			}
		}
		ll ans = 0;
		fo(i,0,brr.size()-1){
			ans+=brr[i];
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
