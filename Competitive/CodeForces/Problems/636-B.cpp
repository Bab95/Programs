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
		ll n;
		cin>>n;
		if(n%4!=0){
			cout<<"NO"<<endl;
			return;
		}
		cout<<"YES"<<endl;
		vector<int> ans(n/2,0);
		ans[0] = 2;
		ans[1] = 4;
		//ans[n/2] = 1
		//ans[n/2+1] = 5;
		unordered_set<int> odds;
		odds.insert(1);
		odds.insert(5);
		for(int i=2;i<n/2-1;i+=2){
			ans[i] = ans[i-1] + 2;
			ans[i+1] = ans[i] + 2;
			int sum = ans[i]+ans[i+1];
			sum = sum/2;
			int a = sum-2;
			int b = sum+2;
			while(a>1){
				if(odds.find(a)==odds.end()&&odds.find(b)==odds.end()){
					odds.insert(a);
					odds.insert(b);
					break;
				}
				a-=2;
				b+=2;
			}
		}
		for(auto it=odds.begin();it!=odds.end();++it){
			ans.pb(*it);
		}
		sort(ans.begin()+n/2,ans.end());
		print(ans,ans.size());
}
int main(){
		speed;
		int t;
		cin>>t;
		while(t--){
				solve();
		}
}
