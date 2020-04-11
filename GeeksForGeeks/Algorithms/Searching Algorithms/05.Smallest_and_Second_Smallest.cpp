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
    int first = arr[0];
    int i = 0;
    while(i<n-1&&arr[i]==arr[i+1]){
        i++;
    }
    if(i==n-1||arr[i+1]==first){
        cout<<-1<<endl;
    }
    else{
        cout<<first<<" "<<arr[i+1]<<endl;
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
