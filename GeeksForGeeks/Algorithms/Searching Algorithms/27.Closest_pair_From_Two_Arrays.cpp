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
int mod(int x){
    if(x<0){
        return -1*x;
    }
    return x;
}
void solve(){
    int m,x,n;
    cin>>m>>n;
    vector<int> arr(m);
    vector<int> brr(n);
    input(arr,m);
    input(brr,n);
    cin>>x;
    int l = 0;
    int r = n-1;
    int diff = INT_MAX;
    pair<int,int> ans;
    while(l<=m-1&&r>=0){
        if(mod(arr[l]+brr[r]-x)<diff){
            ans.first = l;
            ans.second = r;
            diff = mod(arr[l]+brr[r]-x);
        }
        if(arr[l]+brr[r]>x){
            r--;
        }else{
            l++;
        }
    }
    cout<<arr[ans.first]<<" "<<brr[ans.second]<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}