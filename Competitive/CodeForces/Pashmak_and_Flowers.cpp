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
		ulli n;
		cin>>n;
		vector<ulli> arr(n);
		input(arr,n);
		sort(arr.begin(),arr.end());
		int i = 1;
		ulli left_count = 1;
		while(i<n-1&&arr[i]==arr[i-1]){
			i++;
			left_count++;
		}
		i = n-2;
		ulli right_count = 1;
		while(i>=1&&arr[i]==arr[i+1]){
			i--;
			right_count++;
		}
		//cout<<"l:"<<left_count<<" r:"<<right_count<<endl;
		cout<<arr[n-1]-arr[0]<<" ";
		if(n>1&&arr[0]==arr[n-1]){
			cout<<(n*(n-1))/2<<endl;
			return;
		}else{
			cout<<(left_count*right_count)<<endl;
		}
}
int main(){
		speed;
		solve();
}
