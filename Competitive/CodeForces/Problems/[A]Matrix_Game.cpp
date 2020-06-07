#include <bits/stdc++.h>
using namespace std;
#define speed ios::sync_with_stdio(0);cin.tie(0)
typedef long long int ll;
void solve(){
    int m,n;
    cin>>n>>m;
    string p1 = "Ashish";
    string p2 = "Vivek";
    vector<vector<int> > mat(n,vector<int>(m));
    vector<bool> s_row(n,true);
    vector<bool> s_col(m,true);
    int sr = 0;
    int sc = 0;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>mat[i][j];
            if(mat[i][j]!=0){
                s_row[i] = false;
                s_col[j] = false;
            }
        }
    }
    for(int i=0;i<s_row.size();++i){
        if(s_row[i]){
            sr++;
        }
    }
    for(int i=0;i<s_col.size();++i){
        if(s_col[i]){
            sc++;
        }
    }
    int rem = min(sr,sc);
    if(rem%2==0){
        cout<<p2<<endl;
    }else{
        cout<<p1<<endl;
    }
}
int main(){
    speed;
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
