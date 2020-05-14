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
void print(vector<ulli>& ans,int n){
    fo(i,0,n-1){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
bool mycompare(ulli const &a,ulli const &b){
    if(a%3==0&&a/3==b){
        return true;
    }
    if(b==2*a){
        return true;
    }
    return false;
}
bool sortbyascending(ulli const &a,ulli const &b){
    if(a<b){
        return true;
    }
    return false;
}

void solve(){
    int n;
    cin>>n;
    vector<ulli> arr(n);
    unordered_map<ulli,ulli> prev,next;
    unordered_set<ulli> s;
    fo(i,0,n-1){
        cin>>arr[i];
        s.insert(arr[i]);
    }
    fo(i,0,n-1){
        if(arr[i]%3==0&&s.find(arr[i]/3)!=s.end()){
            prev[arr[i]/3] = arr[i];
            next[arr[i]] = arr[i]/3;
        }
        if(arr[i]%2==0&&s.find(arr[i]/2)!=s.end()){
            prev[arr[i]] = arr[i]/2;
            next[arr[i]/2] = arr[i];
        }
    }
    ulli start = -1;
    fo(i,0,n-1){
        if(prev.find(arr[i])==prev.end()){
            start = arr[i];
            break;
        }
    }
    cout<<start<<" ";
    while(next.find(start)!=next.end()){
        cout<<next[start]<<" ";
        start = next[start];
    }
    cout<<endl;
}
int main(){
    solve();
}