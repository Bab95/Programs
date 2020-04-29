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
int mod(int a){
    if(a<0){
        return -1*a;
    }
    return a;
}
void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    vector<int> arr(a);
    vector<int> brr(b);
    vector<int> crr(c);
    input(arr,a);
    input(brr,b);
    input(crr,c);
    int i = 0;
    int j = 0;
    int k = 0;
    vector<int> ans(3);
    int diff = INT_MAX;
    while(i<a&&j<b&&k<c){
        int minelement = min(arr[i],min(brr[j],crr[k]));
        int maxelement = max(arr[i],max(brr[j],crr[k]));
        if(maxelement-minelement<diff){
            diff = maxelement-minelement;
            
            ans[0] = i;
            ans[1] = j;
            ans[2] = k;

        }

        if(diff==0){
            break;
        }

        if(minelement==arr[i]){
            ++i;
        }else if(minelement==brr[j]){
            ++j;
        }else if(minelement==crr[k]){
            ++k;
        }
    }
    print(ans);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}