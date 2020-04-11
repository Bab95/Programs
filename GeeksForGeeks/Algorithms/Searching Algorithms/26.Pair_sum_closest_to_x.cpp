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
void input(vector<int>& arr,int n){
    fo(i,0,n-1){
        cin>>arr[i];
    }
}
int mod(int a){
    if(a<0){
        return -1*a;
    }
    return a;
}
void solve(){
    int n,x;
    cin>>n;
    vector<int> arr(n);
    input(arr,n);
    cin>>x;
    int l = 0,r = n-1;
    int diff = INT_MAX;
    pair<int,int> ans;
    while(l<r){
        if(mod(arr[l]+arr[r]-x)<diff){
            ans.first = l;
            ans.second = r;
            diff = mod(arr[l]+arr[r]-x);
        }
        if(arr[l]+arr[r]>x){
            r--;
        }else{
            l++;
        }
    }
    cout<<arr[ans.first]<<" "<<arr[ans.second]<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    
}

/*
testcases...
2
6
10 22 28 29 30 40
54
5
1 3 4 7 10
15

*/
