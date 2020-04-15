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
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    input(arr,n);
    unordered_map<int,int> mmap;
    pair<int,int> max_freq;//<Freq,Element>
    max_freq.first = 0;
    max_freq.second = 0;
    for(int i=0;i<n;++i){
        mmap[arr[i]]++;
        if(mmap[arr[i]]>max_freq.first){
            max_freq.first = mmap[arr[i]];
            max_freq.second = arr[i];
        } 
    }

    int random_index = (rand()%max_freq.first) + 1;
    fo(i,0,n-1){
        if(arr[i]==max_freq.second){
            random_index--;
        }
        if(random_index==0){
            cout<<i<<endl;
            break;
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}