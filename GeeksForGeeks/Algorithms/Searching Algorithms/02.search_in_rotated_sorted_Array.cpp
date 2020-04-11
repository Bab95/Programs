#include <bits/stdc++.h>
using namespace std;
void input(vector<int>& arr,int n){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}
int findpivot(vector<int>& arr,int start,int end){
    if(start>end){
        return -1;
    }
    int mid = (start+end)/2;
    if(mid<end&&arr[mid]>arr[mid+1]){
        return mid;
    }
    if(mid>start&&arr[mid]<arr[mid-1]){
        return mid-1;
    }
    if(arr[mid]>arr[start]){
        return findpivot(arr,mid+1,end);
    }else if(arr[mid]<arr[start]){
        return findpivot(arr,start,mid-1);
    }
    return -1;
}
int b(vector<int>& arr,int start,int end,int k){
    while(start<=end){
        int mid = (start+end)/2;
        if(arr[mid]==k){
            return mid;
        }else if(k>arr[mid]){
            start = mid+1;
        }else{
            end = mid-1;
        }
    }
    return -1;
}

void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    input(arr,n);
    int k;
    cin>>k;
    int pivot = findpivot(arr,0,n-1);
    //cout<<"pivot: "<<pivot<<endl;
    int start = 0;
    int end = n-1;
    int index;
    if(pivot==-1){
        index = b(arr,0,n-1,k);
    }else if(k==arr[pivot]){
        index = pivot;
    }else if(k>=arr[0]){
        //cout<<"searching "<<k<<" here"<<endl;
        index = b(arr,0,pivot-1,k);

    }else{
        //cout<<"...."<<endl;
        index = b(arr,pivot+1,end,k);
    }

    if(index!=-1){
            cout<<index<<endl;
    }else{
        cout<<-1<<endl;
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
