#include <bits/stdc++.h>
using namespace std;
void input(vector<int>& arr,int n){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}
void bianrysearch(vector<int>& arr,int start,int end,int k,vector<int>& res){
    if(start>end){
        return;
    }
    int mid = (start+end)/2;
    if(arr[mid]==k){
        res[0] = min(res[0],mid);
        res[1] = max(res[1],mid);
        bianrysearch(arr,start,mid-1,k,res);
        bianrysearch(arr,mid+1,end,k,res);
    }else if(arr[mid]>k){
        bianrysearch(arr,start,mid-1,k,res);
    }else{
        bianrysearch(arr,mid+1,end,k,res);
    }
}
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    input(arr,n);
    if(k>arr[n-1]||k<arr[0]){
        cout<<-1<<endl;
        return;
    }
    vector<int> res(2);
    res[0] = INT_MAX;
    res[1] = INT_MIN;
    bianrysearch(arr,0,n-1,k,res);
    if(res[0]==INT_MAX&&res[1]==INT_MIN){
        cout<<"-1"<<endl;
        return;
    }
    cout<<(res[1]-res[0]+1)<<endl;
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
