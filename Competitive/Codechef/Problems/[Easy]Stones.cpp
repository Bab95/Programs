#include <bits/stdc++.h>
using namespace std;
#define speed ios::sync_with_stdio(0);cin.tie(0)
typedef long long int ll;
void print(vector<ll>& arr,int n){
    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void operation(vector<ll>& arr){
    ll m_val;
    m_val = arr[0];
    int n = arr.size();
    for(int i=1;i<n;++i){
        m_val = max(arr[i],m_val);
    }
    for(int i=0;i<n;++i){
        arr[i] = m_val-arr[i];
    }

}
void solve(){
    int n;
    ll k;
    cin>>n>>k;
    vector<ll> arr(n);
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    if(k==0){
        print(arr,n);
    }else{
        operation(arr);
        if(k%2==0){
            operation(arr);
        }
        print(arr,n);
    }
}
int main(){
    speed;
    solve();
}
