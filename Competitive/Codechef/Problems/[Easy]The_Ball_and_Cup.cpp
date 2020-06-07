#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,c,q;
    cin>>n>>c>>q;
    vector<pair<int,int> > flips(q);
    for(int i=0;i<q;++i){
        cin>>flips[i].first>>flips[i].second;
    }
    int pos = c;
    for(int i=0;i<flips.size();++i){
        if(pos<flips[i].first||pos>flips[i].second){
            continue;
        }else{
            int tmp = flips[i].second-pos;
            pos = flips[i].first+tmp;
        }
    }
    cout<<pos<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
