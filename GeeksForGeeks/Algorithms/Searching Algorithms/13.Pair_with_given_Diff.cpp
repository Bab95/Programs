#include <bits/stdc++.h>
using namespace std;
void input(vector<int>& arr,int n){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}
int binarysearch(vector<int>& arr,int start,int end,int k){
    if(start>end){
        return -1;
    }
    int mid = (start+end)/2;
    if(arr[mid]==k){
        return mid;
    }else if(arr[mid]<k){
        return binarysearch(arr,mid+1,end,k);
    }
    return binarysearch(arr,start,mid-1,k);

}
void solve(){
    int n,diff;
    cin>>n>>diff;
    vector<int> arr(n);
    input(arr,n);
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        if(arr[i]+diff>arr[n-1]){
            cout<<"-1"<<endl;
            break;
        }else{
            int ans = binarysearch(arr,i+1,n-1,arr[i]+diff);
            if(ans!=-1){
                cout<<1<<endl;
                break;
            }
        }
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
