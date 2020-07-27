#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <list>
#include <string.h>
#include <string>
using namespace std;
#define fo(i,l,r) for(int i=l;i<=r;++i)
#define fi(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back
#define po pop_back
#define INF 1e9+9
void input(vector<int>& arr,int n){
	fo(i,0,n-1){
		cin>>arr[i];
	}
}
void solve(){
	string s;
	cin>>s;
	int ans = 0;
	if(s.length()<3){
		cout<<0<<endl;
		return;
	}
	for(int i=0;i<s.length()-2;++i){
		if(s[i]=='Q'){
			for(int j=i+1;j<s.length()-1;j++){
				if(s[j]=='A'){
					for(int k=j+1;k<s.length();++k){
						if(s[k]=='Q'){
							ans++;
						}
					}
				}
			}
		}
	}
	cout<<ans<<endl;
}
int main(){
	solve();
	return 0;
}
