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
		ll n,m;
		cin>>n>>m;
		ulli max_size = (n-m+1);
		ulli ans1 = (max_size%2==0)?(max_size/2*(max_size-1)):((max_size-1)/2)*(max_size);
		ulli min_team_size = (n/m);
		ulli min_team_size_with_extra_player = (n%m==0)?-1:(min_team_size+1);
		ulli ans2 = 0;
		if(min_team_size>1){
			ans2 = ((min_team_size*(min_team_size-1))/2)*(m-n%m);
		}
		if(min_team_size_with_extra_player!=-1){
			ans2+=(min_team_size_with_extra_player*(min_team_size_with_extra_player-1))/2*(n%m);
		}
		cout<<ans2<<" "<<ans1<<endl;
}
int main(){
		speed;
		solve();
}
