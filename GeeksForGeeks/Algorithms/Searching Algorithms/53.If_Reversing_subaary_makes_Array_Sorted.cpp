#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <unordered_map>
#include <map>
#include <limits.h>
#include <unordered_set>
#include <stack>
#define fo(i,l,r) for(int i=l;i<=r;++i)
#define fi(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back
#define po pop_back
using namespace std;
void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void input(vector<int>& arr,int n){
    fo(i,0,n-1){
        cin>>arr[i];
    }
}
void print(vector<int>& ans,int n){
    fo(i,0,n-1){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
/*int findBitonicPoint(vector<int>& arr,int start,int end){
    if(start==end){
        return start;
    }
    if(start>end){
        return -1;
    }
    int mid = (start+end)/2;
    if(mid>end&&arr[mid]>arr[mid+1]){
        if(mid>start&&arr[mid]>arr[mid+1]){
            return mid;
        }else{
            return findBitonicPoint(arr,start,mid-1);
        }
    }else{
        return findBitonicPoint(arr,mid+1,end);
    }
    return -1;

}*/
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    input(arr,n);
    
    int i,j,k;
    //first increasing part....
    int i = 1;
    while(i<n&&arr[i]>arr[i-1]){
        ++i;
    }
    //second decreasing part....
    j = i;
    while(j<n&&arr[j]<arr[j-1]){
        ++j;
    }
    if(j==n){
        cout<<"possible"<<endl;
        return;
    }
    //Third part again increasing if exists...
    //start of 3rd part shoud be greater than End of 2nd part when reversed and third part should start at atleast index 2.....
    k = j;
    if(arr[k]<arr[i-1]){
        cout<<"Not Possible"<<endl;
        return;
    }
    while(k>1&&k<n){
        if(arr[k]<arr[k-1]){
            cout<<"Not Possible"<<endl;
            return;
        }
        ++k;
    }
    cout<<"Possible"<<endl;
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}