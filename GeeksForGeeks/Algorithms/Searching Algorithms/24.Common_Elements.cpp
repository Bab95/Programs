#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <unordered_map>
#include <map>
#include <limits.h>
#include <unordered_set>
#define fo(i,l,r) for(int i=l;i<=r;i++)
#define fi(i,r,l) for(int i=r;i>=l;i--)
#define pb push_back
#define po pop_back
using namespace std;
void input(vector<long long int>& arr,int n){
    fo(i,0,n-1){
        cin>>arr[i];
    }
}
void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    vector<long long int> arr(a);
    vector<long long int> brr(b);
    vector<long long int> crr(c);
    input(arr,a);
    input(brr,b);
    input(crr,c);
    unordered_map<long long int,int> ans;
    int i=0,j=0,k=0;
    while(i<a&&j<b&&k<c){
        if(arr[i]==brr[j]&&arr[i]==crr[k]){
            ans[arr[i]]++;
            i++;
            j++;
            k++;
        }else if(arr[i]<brr[j]){
            i++;
        }else if(brr[j]>crr[k]){
            k++;
        }else{
            j++;
        }
    }
    if(ans.size()==0){
        cout<<-1<<endl;
        return;
    }
    vector<long long int> v;
    for(auto it=ans.begin();it!=ans.end();++it){
        v.push_back(it->first);
        //cout<<it->first<<" ";
    }
    sort(v.begin(),v.end());
    fo(i,0,v.size()-1){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}