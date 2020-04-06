#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int max(int a,int b){
    return a>b?a:b;
}
int LargestSubarray(vector<int>& arr,int n,int k){
    unordered_map<int,int> mmap;
    int sum = 0;
    int result = 0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum==k){
            result = max(result,i+1);
        }
        if(mmap.count(sum-k)!=0){
            result = max(result,i-mmap[sum-k]);
        }
        if(mmap.count(sum)==0){
            mmap[sum] = i;
        }
    }
    return result;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int k,n;
	    cin>>n>>k;
	    vector<int> arr(n);
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    int result = LargestSubarray(arr,n,k);
	    cout<<result<<endl;
	}
	return 0;
}
