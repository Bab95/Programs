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
#include <string.h>
#include <math.h>
#define fo(i,l,r) for(int i=l;i<=r;++i)
#define fi(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back
#define po pop_back
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long int ll;
typedef unsigned long long int ulli;
#define M 1000001
#define _y "YES"
#define _n "NO"
using namespace std;
bool primes[M+1];
void generatePrimes(){
	memset(primes,true,sizeof(primes));
	for(int i=2;i*i<=M;++i){
		if(primes[i]==true){
			for(int j=i*i;j<=M;j=j+i){
				primes[j] = false;
			}
		}
	}
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
		int n;
		cin>>n;
		vector<ll> arr(n);
		input(arr,n);

		fo(i,0,n-1){
      if(arr[i]==1){
				cout<<_n<<endl;
				continue;
			}
			double sq = sqrt((double)arr[i]);
			int index = 0;
			if(sq-floor(sq)==0){
				index = (int)sq;
				if(primes[index]){
					cout<<_y<<endl;
				}else{
					cout<<_n<<endl;
				}
			}else{
				cout<<_n<<endl;
				continue;
			}
		}
}
int main(){
		speed;
		generatePrimes();
		solve();
}
