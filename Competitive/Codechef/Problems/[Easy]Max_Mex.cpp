#include <bits/stdc++.h>
using namespace std;
void input(vector<int>& arr){
    for(int i=0;i<arr.size();++i){
        cin>>arr[i];
    }
}
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    input(arr);
    sort(arr.begin(),arr.end());
    int maxval = arr[n-1];
    vector<int> missing;
    for(int i=0,j=0;i<=maxval;++i){
        if(j<n&&i==arr[j]){
            while(j<n&&i==arr[j])
                j++;
        }else{
            missing.push_back(i);
        }
    }
    if(missing.size()==0){
        cout<<maxval+k+1<<endl;
    }else if(missing.size()>k){
        cout<<missing[k]<<endl;
    }else if(missing.size()<=k){
        cout<<maxval+(k-missing.size())+1<<endl;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
