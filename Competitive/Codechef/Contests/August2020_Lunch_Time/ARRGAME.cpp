#include <bits/stdc++.h>
using namespace std;
void input(vector<int>& arr,int n){
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
}
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    int zeros = 0;
    vector<int> segments;
    for(int i=0;i<n;++i){
        cin>>arr[i];
        if(arr[i]==0){
            zeros++;
        }else if(arr[i]==1){
            if(zeros==0){
                continue;
            }
            segments.push_back(zeros);
            zeros = 0;
        }
    }
    if(segments.size()==0){
        cout<<"No"<<endl;
        return;
    }
    sort(segments.rbegin(),segments.rend());
    if(segments.size()==1){
        if(segments[0]%2==1){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }else if(segments.size()>=2){
        if(segments[0]==segments[1]){
            cout<<"No"<<endl;
        }else if(segments[0]%2==0){
            cout<<"No"<<endl;
        }else if(segments[0]>=2*segments[1]+1){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        //cout<<"#"<<t<<"-->";
        solve();
    }
}