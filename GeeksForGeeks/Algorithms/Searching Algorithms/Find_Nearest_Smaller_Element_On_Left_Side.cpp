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
    int n;
    cin>>n;
    vector<int> arr(n);
    input(arr,n);
    vector<int> ans;
    ans.pb(-1);
    stack<int> stk;
    stk.push(arr[0]);
    fo(i,1,n-1){
        if(stk.top()<arr[i]){
            ans.pb(stk.top());
            stk.push(arr[i]);
        }else{
            while(!stk.empty()&&stk.top()>arr[i]){
                stk.pop();
            }
            if(stk.empty()){
                ans.pb(-1);
            }else{
                ans.pb(stk.top());
            }
            stk.push(arr[i]);
        }
    }
    print(ans,n);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}