#include <bits/stdc++.h>
using namespace std;
void input(vector<int>& arr,int n){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}
int search(vector<int>& arr,int start,int end){
    //cout<<"(start: "<<start<<","<<"end:"<<end<<")\n";
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
            }else if(mid==start){
                return mid;
            }
            return search(arr,start,mid-1);
        }else{
            return search(arr,mid+1,end);
        }
    }
    return -1;
}
int revbinarysearch(vector<int>& arr,int start,int end,int k){
    if(start>end){
        return -1;
    }
    int mid = (start+end)/2;
    if(arr[mid]==k){
        return mid;
    }else if(arr[mid]>k){
        return revbinarysearch(arr,mid+1,end,k);
    }
    return revbinarysearch(arr,start,mid-1,k);
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
    int n,k;
    cin>>n;
    vector<int> arr(n);
    input(arr,n);
    cin>>k;
    int max_index = search(arr,0,n-1);
    //cout<<"max_index: "<<max_index<<endl;
    int ans;
    if(max_index==-1){
        ans = revbinarysearch(arr,0,n-1,k);
    }else if(max_index==n-1){
        ans = binarysearch(arr,0,n-1,k);
    }else if(arr[max_index]==k){
        ans = max_index;
    }else{
        int tmp1=-1,tmp2=-1;
        if(k>=arr[n-1]){
            tmp1 = revbinarysearch(arr,max_index+1,n-1,k);
        }
        if(k>=arr[0]){
            tmp2 = binarysearch(arr,0,max_index-1,k);
        }
        //cout<<tmp1<<" "<<tmp2<<endl;
        ans = (tmp1!=-1)?tmp1:tmp2;
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
