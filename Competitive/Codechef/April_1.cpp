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
bool solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    input(arr,n);
    int i = 0;
    while(i<n&&arr[i]==0){
        ++i;
    }
    int current_dist = 0;
    int people = 0;
    for(;i<n;++i){
        if(arr[i]==0){
            ++current_dist;
        }else{
            ++people;
            //cout<<current_dist<<" "<<people<<endl;
            if(current_dist<5&&people>1){
                return false;
            }
            current_dist = 0;
        }
    }
    //cout<<people<<endl;
    return true;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        if(solve()){
            cout<<"YES";
        }else{
            cout<<"NO";
        }
        cout<<endl;
    }
}