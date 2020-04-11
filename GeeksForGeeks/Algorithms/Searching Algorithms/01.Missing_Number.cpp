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
    vector<int> arr(n-1);
    input(arr,n-1);
    int sum = 0;
    for(int i=0;i<n-1;i++){
        sum+=arr[i];
    }
    long long int N = (n%2==0)?((n/2)*(n+1)):(((n+1)/2)*n);
    cout<<N-sum<<endl;
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
