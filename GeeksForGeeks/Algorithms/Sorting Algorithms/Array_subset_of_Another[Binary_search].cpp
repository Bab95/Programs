#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
void input(vector<int>& arr,int n){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}
bool binarySearch(vector<int>& arr,int start,int end,int key){
    if(start>end){
        return false;
    }
    int mid = (start+end)/2;
    if(arr[mid]==key){
        return true;
    }
    else if(arr[mid]>key){
        return binarySearch(arr,start,mid-1,key);
    }else{
        return binarySearch(arr,mid+1,end,key);
    }
    return false;
}
int main() {
	//code
	int t,m,n;
	cin>>t;
	while(t--){
	    cin>>m>>n;
	    vector<int> arr(m);
	    vector<int> brr(n);
	    input(arr,m);
	    input(brr,n);
	    sort(arr.begin(),arr.end());
	    bool ans = true;
	    for(int i=0;i<brr.size();++i){
	        if(!binarySearch(arr,0,m-1,brr[i])){
	            ans = false;
	            break;
	        }
	    }
	    if(ans){
	        cout<<"Yes"<<endl;
	    }else{
	        cout<<"No"<<endl;
	    }
	}

	return 0;
}
