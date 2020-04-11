#include <bits/stdc++.h>
using namespace std;
void input(vector<int>& arr,int n){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}
int mod(int a){
    if(a<0){
        return -1*a;
    }
    return a;
}
void print(vector<int>& arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
void solve(){

    int n;
    cin>>n;
    vector<int> arr(n);
    input(arr,n);
    sort(arr.begin(),arr.end());
    int l = 0;
    int r = n-1;
    int p_ans = INT_MAX;
    int ans = -1;
    while(l<r){
        int tmp = arr[l]+arr[r];
        if(mod(tmp)<p_ans){
            p_ans = mod(tmp);
            ans = tmp;
        }
        if(arr[l]+arr[r]<0){
            l++;
        }else{
            r--;
        }
    }
    cout<<ans<<endl;
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
