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
#include <string.h>
#define fo(i,l,r) for(int i=l;i<=r;++i)
#define fi(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back
#define po pop_back
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long int ll;
typedef unsigned long long int ulli;
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
void input(vector<ll>& arr,int n){
  fo(i,0,n-1){
    cin>>arr[i];
  }
}
void input(vector<ulli>& arr,int n){
    fo(i,0,n-1){
        cin>>arr[i];
    }
}
ll max(ll a,ll b){
    return a>b?a:b;
}
ulli max(ulli a,ulli b){
    return a>b?a:b;
}
int max(int a,int b){
    return a>b?a:b;
}
void print(vector<int>& ans,int n){
    fo(i,0,n-1){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
void print(vector<ll>& ans,int n){
    fo(i,0,n-1){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
void heapify(vector<int>& arr,int i,int size){
    int left = 2*i;
    int right = 2*i+1;
    int num = arr[i];
    while(right<=n){
        if(num<=arr[left]&&num<=arr[right]){
            arr[i] = num;
        }else if(arr[left]<arr[right]){
            arr[i] = arr[left];
            i = left;
        }else{
            arr[i] = arr[right];
            i = right;
        }
        left = 2*i;
        right = 2*i + 1;
    }
}
void BuildHeap(vector<int>& arr,int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,i,n);
    }
}
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    input(arr,n);
    priority_queue<int,vector<int>,greater<int> > pq(arr.begin(),arr.begin()+k);
    int index = 0;
    for(int i=k;i<n;++i){
        arr[index++] = pq.top();
        pq.pop();
        pq.push(arr[i]);
    }
    for(int i=0;i<k;++i){
        arr[index++] = pq.top();
        pq.pop();
    }
    print(arr,n);
}
int main(){
    speed;
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
