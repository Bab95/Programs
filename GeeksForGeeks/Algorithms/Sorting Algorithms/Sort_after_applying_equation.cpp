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
long long int a,b,c;
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
void solve(){
    int n;
    cin>>a>>b>>c;
    cin>>n;
    vector<ll> arr(n);
    vector<ll> ans(n);
    input(arr,n);
    fo(i,0,n-1){
        ans[i] = (a*arr[i]*arr[i])+(b*arr[i])+c;
    }
    sort(ans.begin(),ans.end());
    print(ans,n);
}
int main(){
    speed;
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
/*-26726832966634 -26481521211650 -26329600160074 -26313113335634 -26215383801277 -25652434966109 -24009696227177 -23683291872745 -23107173189730 -22631790051305 -20541153804010 -18936721636514 -18859410058265 -18025015307354 -17832693655549 -17304702701149 -16419781900402 -16254380312089 -15988584032477 -13386791531410 -13363286525450 -12611368276829 -12514940863930 -11502517793305 -11412606519034 -11069992089010 -10944186665602 -10712246211229 -9735699094402 -8511422273410 -7929812531677 -7580234752874 -7566085243402 -7488499218490 -7469743274269 -6884446904189 -6478587573370 -5942155002610 -5887447129250 -5805595057177 -4877598665114 -4700389173074 -3928642079977 -3467846296349 -3141586350490 -2953120937914 -2685910684009 -2665934960669 -2487147303194 -2403730491802 -2335790318569 -2175579555289 -1994649715549 -1864914390802 -1599768316009 -1484850922345 -1046859930985 -937226409034 -840906159010 -393044996029 -357875301154 -340156004989 -167852550109 -15353495410 */
