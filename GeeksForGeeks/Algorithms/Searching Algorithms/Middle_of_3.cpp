#include <bits/stdc++.h>
using namespace std;
void input(vector<int>& arr,int n){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}
void solve(){
    int n;
    n = 3;
    vector<int> arr(n);
    input(arr,n);
    sort(arr.begin(),arr.end());
    cout<<arr[1]<<endl;
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
