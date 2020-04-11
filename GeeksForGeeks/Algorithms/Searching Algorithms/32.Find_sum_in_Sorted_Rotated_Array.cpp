#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <unordered_map>
#include <map>
#include <limits.h>
#include <unordered_set>
#define fo(i,l,r) for(int i=l;i<=r;i++)
#define fi(i,r,l) for(int i=r;i>=l;i--)
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
int findPivot(vector<int>& arr,int start,int end){
    if(start>end){
        return -1;
    }
    int mid = (start+end)/2;
    if(mid<end&&arr[mid]>arr[mid+1]){
        return mid+1;
    }
    if(mid>start&&arr[mid]<arr[mid-1]){
        return mid;
    }
    if(arr[mid]>arr[start]){
        return findPivot(arr,mid+1,end);
    }
    return findPivot(arr,start,mid-1);
}
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    input(arr,n);
    int sum;
    cin>>sum;
    int pivot = findPivot(arr,0,n-1);
    int l = -1,r=-1;
    pair<int,int> ans;
    if(pivot==-1){
        l = 0;
        r = n-1;
        while(l<r){
            if(arr[l]+arr[r]==sum){
                cout<<arr[l]<<" "<<arr[r]<<endl;
                ans.first = l;
                ans.second = r;
                break;
            }else if(arr[l]+arr[r]>sum){
                --r;
            }else{
                ++l;
            }
        }
    }else{
        l = pivot;
        r = pivot-1;
        while(l!=r){
            if(arr[l]+arr[r]==sum){
                cout<<arr[l]<<" "<<arr[r]<<endl;
                ans.first = l;
                ans.second = r;
                break;
            }else if(arr[l]+arr[r]>sum){
                r--;
                if(r==0){
                    r = n-1;
                }
            }else{
                l = (l+1)%(n);
            }
        }
    }
    cout<<ans.first<<" "<<ans.second<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}

/*
testcases....
3
6
11 15 26 38 9 10
35
6
11 15 26 38 9 10
19
6
11 15 6 8 9 10
16

*/