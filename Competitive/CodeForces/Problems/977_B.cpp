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
#define fo(i,l,r) for(int i=l;i<=r;++i)
#define fi(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back
#define po pop_back
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
void solve(){
	int n;
	cin>>n;
	string s;
	s.reserve(n);
	cin>>s;
	unordered_map<string,int> mmap;
	
	fo(i,0,s.length()-2){
		string key = s.substr(i,2);
		mmap[key]++;
	}
	pair<string,int> ans;
	ans.second = -1;
	for(auto it=mmap.begin();it!=mmap.end();++it){
		//cout<<it->first<<" "<<it->second<<endl;
		if(it->second>ans.second){
			ans.first = it->first;
			ans.second = it->second;
		}
	}
	cout<<ans.first<<endl;
}
int main(){
	solve();
}