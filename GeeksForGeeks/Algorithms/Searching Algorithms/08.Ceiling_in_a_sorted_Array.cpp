#include <bits/stdc++.h>
using namespace std;
void input(vector<int>& arr,int n){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}
int binarySearch(vector<int>& arr,int start,int end,int k){

    int ans = INT_MAX;
    while(start<=end){
        int mid = (start+end)/2;
        if(arr[mid]<ans&&arr[mid]>=k){
            ans = arr[mid];
        }
        if(arr[mid]>k){
            end = mid-1;
        }else{
            start = mid + 1;
        }
    }
    return ans;
}
void solve(){
    int n,k;
    cin>>n;
    vector<int> arr(n);
    input(arr,n);
    cin>>k;
    //vector<int>::iterator a = upper_bound(arr.begin(),arr.end(),k);
    //cout<<arr[a-arr.begin()]<<endl;
    int ans = binarySearch(arr,0,n-1,k);
    if(ans==INT_MAX){
        cout<<"Not Possible"<<endl;
    }else{
        cout<<ans<<endl;
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
