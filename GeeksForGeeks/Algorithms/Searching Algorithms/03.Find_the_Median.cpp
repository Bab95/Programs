#include <bits/stdc++.h>
using namespace std;
void input(vector<int>& arr,int n){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    input(arr,n);
    sort(arr.begin(),arr.end());
    if(n%2==0){
        cout<<(arr[n/2]+arr[n/2-1])/2<<endl;
    }else{
        cout<<arr[n/2]<<endl;
    }
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
