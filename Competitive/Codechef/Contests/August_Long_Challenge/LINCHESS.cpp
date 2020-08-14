#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define speed ios_base::sync_with_stdio(false); cin.tie(NULL)
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    int ans = INT_MAX;
    int banda = -1;
    for(int i=0;i<n;++i){
        if(arr[i]>k){
            continue;
        }else if(!(k%arr[i])){
            int tmp = k/arr[i];
            if(tmp<ans){
                ans = tmp;
                banda = arr[i];
            }
        }
    }
    cout<<banda<<endl;
}
int main(){
    int t;
    //freopen("input.txt","r",stdin);
    speed;
    cin>>t;
    while(t--){
        solve();
    }
}

/*
6
4 3 2 8
*/
