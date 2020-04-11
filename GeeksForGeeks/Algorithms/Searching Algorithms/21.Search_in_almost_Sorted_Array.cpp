#include <iostream>
#include <vector>
using namespace std;
void input(vector<int>& arr,int n){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}
int binarySearch_modified(vector<int>& arr,int start,int end,int key){
    if(start>end){
        return -1;
    }
    int mid = (start+end)/2;
    if(arr[mid]==key){
        return mid;
    }
    if(mid>start&&arr[mid-1]==key){
        return mid-1;
    }
    if(mid<end&&arr[mid+1]==key){
        return mid+1;
    }
    if(arr[mid]>key){
        return binarySearch_modified(arr,start,mid-2,key);
    }
    return binarySearch_modified(arr,mid+2,end,key);
}
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    input(arr,n);
    int x;
    cin>>x;
    int ans = binarySearch_modified(arr,0,n-1,x);
    if(ans!=-1){
        cout<<ans<<endl;
    }else{
        cout<<"Not present"<<endl;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}

/*
    test cases:
2
7
10 3 40 20 50 80 70
90
7
10 3 40 20 50 80 70
40

*/