#include <bits/stdc++.h>
using namespace std;
void solve2(){
    int n,m;
    cin>>n>>m;
    vector<vector<int> > mat(n,vector<int>(m));
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>mat[i][j];
        }
    }
    long long int ans = 0;
    for(int i=0;i<(n+1)/2;++i){
        for(int j=0;j<(m+1)/2;++j){
            vector<int> current;
            int x = n-i-1;
            int y = m-j-1;
            current.push_back(mat[i][j]);
            if(x!=i){
                current.push_back(mat[x][j]);
            }
            if(y!=j){
                current.push_back(mat[i][y]);
            }
            if(x!=i&&y!=j){
                current.push_back(mat[x][y]);
            }
            sort(current.begin(),current.end());
            if(current.size()==2){
                ans += (current[1]-current[0]);
            }else if(current.size()==4){
                ans += (current[3]+current[2]-current[1]-current[0]);
            }
        }
    }

    cout<<ans<<endl;
}
int main(){
  int t;
  cin>>t;
  while(t--){
    solve2();
  }
}
