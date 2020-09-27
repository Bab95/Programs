#include <bits/stdc++.h>
using namespace std;
//Solution1:......................................
int binarySearch(vector<int>& arr,int low,int high,int &n){
    if(low>high){
        return -1;
    }
    int mid = (low+high)/2;
    if(mid>0&&arr[mid]<arr[mid-1]){
        return mid;
    }else if(mid<n-1&&arr[mid]>arr[mid+1]){
        return mid+1;
    }else{
        if(arr[low]>=arr[mid]){
            return binarySearch(arr,low,mid-1,n);
        }else{
            return binarySearch(arr,mid,high,n);
        }
    }
    return -1;
}
//Solution2:........................................
int findMin(vector<int>& nums) {
    int ans = INT_MAX;
    int low = 0;
    int high = nums.size()-1;
    while(low<=high){
        int mid = (low+high)/2;
        ans = min(ans,nums[mid]);
        if(nums[low]<nums[mid]){
            //obviously we are in the increasing segment i.e. before pivot element.
            ans = min(ans,nums[low]);
            low = mid+1;
        }else if(nums[mid]<nums[high]){
            ans = min(ans,nums[mid]);
            high = mid-1;
        }else{
            low++;
        }
    }
    return ans;
}
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    int index = binarySearch(arr,0,n-1,n);
    if(index==-1){
        cout<<arr[0]<<endl;
    }else{
        cout<<arr[index]<<endl;
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