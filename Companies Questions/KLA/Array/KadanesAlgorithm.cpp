#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,k;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    int current_sum = arr[0];
    int max_sum = arr[0];
    for(int i=1;i<n;++i){
        current_sum = max(current_sum+arr[i],arr[i]);
        max_sum = max(max_sum,current_sum);
    }
    cout<<max_sum<<endl;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    solve();
	}
	return 0;
}