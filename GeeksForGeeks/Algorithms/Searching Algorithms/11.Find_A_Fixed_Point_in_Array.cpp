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
    bool flag = false;
    for(int i=0;i<n;i++){
        if(arr[i]==i+1){
            cout<<arr[i]<<" ";
            flag = true;
        }
    }
    if(!flag){
        cout<<"Not Found"<<endl;
    }else{
        cout<<endl;
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
