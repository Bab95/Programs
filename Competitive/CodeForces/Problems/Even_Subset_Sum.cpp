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
	int n;
	cin>>n;
	vector<int> arr(n);
	input(arr,n);
	vector<int> prefix(n,0);
	prefix[0] = arr[0];
	if(prefix[0]%2==0){
		cout<<1<<endl;
		cout<<1<<endl;
		return;
	}
	for(int i=1;i<n;++i){
		prefix[i] = prefix[i-1] + arr[i];
		if(prefix[i]%2==0){
			cout<<i+1<<endl;
			for(int j=0;j<=i;++j){
				cout<<j+1<<" ";
			}
			cout<<endl;
			return;
		}
	}
	int i = 0;
	int first = -1,second = -1;
	for(i=0;i<n;++i){
		if(prefix[i]%2==1){
			if(first==-1){
				first = i;
			}else{
				second = i;
				break;
			}
		}
	}
	if(first!=-1&&second!=-1){
		cout<<second-first<<endl;
		for(int j=first+1;j<=second;++j){
			cout<<j+1<<" ";
		}
		cout<<endl;
	}else{
		cout<<-1<<endl;
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
