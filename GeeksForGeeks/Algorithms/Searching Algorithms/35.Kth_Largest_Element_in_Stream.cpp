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
void print(vector<int>& ans,int n){
    fo(i,0,n-1){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
void solve(){
    int k,n;
    cin>>k>>n;
    vector<int> arr(n);
    priority_queue<int,vector<int>,greater<int> > pq;
    fo(i,0,k-1){
        cin>>arr[i];
        pq.push(arr[i]);
    }
    fo(i,0,k-2){
        cout<<-1<<" ";
    }
    cout<<pq.top()<<" ";
    fo(i,k,n-1){
        cin>>arr[i];
        if(arr[i]>pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
        cout<<pq.top()<<" ";
    }
    cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}