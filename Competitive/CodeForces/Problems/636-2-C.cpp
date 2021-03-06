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
void print(vector<ll>& ans,int n){
		fo(i,0,n-1){
				cout<<ans[i]<<" ";
		}
		cout<<endl;
}
void solve(){
		ll n,k;
		cin>>n>>k;
		vector<ll> arr(n);
		input(arr,n);
		vector<bool> peaks(n,false);
		for(int i=1;i<n-1;){
			if(arr[i]>arr[i-1]&&arr[i]>arr[i+1]){
				peaks[i] = true;
				i = i+2;
				continue;
			}
			++i;
		}
		int current = 0;
		for(int i=1;i<k-1;++i){
			if(peaks[i]){
				++current;
			}
		}
		vector<int> window;
		window.pb(current);
		for(int i=k;i<n;++i){
			if(peaks[i-(k-1)]==true){
				current--;
			}
			if(peaks[i-1]==true){
				current++;
			}
			window.pb(current);
		}
		//print(window,window.size());
		int start = 1;
		int tukde = window[0];
		for(int i=0;i<window.size();++i){
			if(window[i]>tukde){
				tukde = window[i];
				start = i + 1;
			}
		}
		cout<<tukde+1<<" "<<start<<endl;
}
int main(){
		speed;
		int t;
		cin>>t;
		while(t--){
				solve();
		}
}
