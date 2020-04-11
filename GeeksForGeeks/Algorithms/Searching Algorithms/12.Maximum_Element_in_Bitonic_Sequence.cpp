#include <bits/stdc++.h>
using namespace std;
void input(vector<int>& arr,int n){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}
int search(vector<int>& arr,int start,int end){
    if(start==end){
        //return arr[start];
        return start;
    }
    int mid = (start+end)/2;
    if(mid<end){
        if(arr[mid]>arr[mid+1]){
            if(mid>start&&arr[mid]>arr[mid-1]){
                //return arr[mid];
                return mid;
            }
            return search(arr,start,mid-1);
        }else{
            return search(arr,mid+1,end);
        }
    }
    return -1;
}
void solve(){
    int n,k;
    cin>>n;
    vector<int> arr(n);
    input(arr,n);
    cin>>k;
    int max_index = search(arr,0,n-1);
    if(max_index==-1){
        cout<<arr[0]<<endl;
    }else{
        cout<<arr[max_index]<<endl;
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
