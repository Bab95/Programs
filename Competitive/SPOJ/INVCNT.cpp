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
ll merge(vector<ll>& arr,vector<ll>& temp,int start,int mid,int end){
	int i = start;
	int j = mid;
	int k = start;
	ll count = 0 ;
	while(i<mid&&j<=end){
		if(arr[i]<=arr[j]){
			temp[k++] = arr[i++];
		}else{
			count+=(mid-i);
			temp[k++] = arr[j++];
		}
	}
	while(i<mid){
		temp[k++] = arr[i++];
	}
	while(j<=end){
		temp[k++] = arr[j++];
	}
	fo(i,start,end){
		arr[i] = temp[i];
	}
	return count;
}
ll mergeSort(vector<ll>& arr,int start,int end,vector<ll>& temp){
	if(start>=end){
		return 0;
	}
	ll count = 0;
	int mid = (start+end)/2;
	count+=mergeSort(arr,start,mid,temp);
	count+=mergeSort(arr,mid+1,end,temp);
	count+=merge(arr,temp,start,mid+1,end);
	return count;
}
ll countInversions(vector<ll>& arr,int n){
	ll count = 0;
	vector<ll> temp(arr.size());
	count += mergeSort(arr,0,n-1,temp);
	return count;
}
void solve(){
    int n;
    cin>>n;
    vector<ll> arr(n);
    input(arr,n);
    ll ans = countInversions(arr,n);
	cout<<ans<<endl;
}
int main(){
    speed;
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}