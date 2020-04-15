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
#define M 100000000
#define fo(i,l,r) for(int i=l;i<=r;++i)
#define fi(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back
#define po pop_back
using namespace std;
long long int dp[M+1];
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
long long int bigger(long long int n){
    if(n<M){
        return dp[n];
    }
    return max(n,bigger(n/2)+bigger(n/3)+bigger(n/4));
}
long long int solve(long long int n){
    if(n<12){
        return n;
    }
    if(n>M){
        return bigger(n);
    }
    return dp[n];
}
long long int max(long long int a,long long int b){
    return a>b?a:b;
}
void fill(){
    fo(i,1,11){
        dp[i] = i;
    }
    fo(i,12,M){
        dp[i] = max(dp[i/2]+dp[i/3]+dp[i/4],i);
    }
}
int main(){
    long long int n;
    fill();
    while(scanf("%lld",&n)!=EOF){
        cout<<solve(n)<<endl;
    }
}