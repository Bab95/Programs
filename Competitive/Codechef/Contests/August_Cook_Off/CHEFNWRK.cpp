#include <bits/stdc++.h>
using namespace std;
void solve(){
	int n,k;
	cin>>n>>k;
	vector<int> arr(n);
	bool flag = true;
	int sum = 0;
	for(int i=0;i<n;++i){
		cin>>arr[i];
	}
	int current = 0;
	int ans = 0;
	for(int i=0;i<n;++i){
		if(arr[i]>k){
			cout<<-1<<endl;
			return;
		}
		if(current+arr[i]>k){
			ans++;
			current = arr[i];
		}else{
			current += arr[i];
		}
	}
	if(current>0){
		ans += 1;
	}
	cout<<ans<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}
