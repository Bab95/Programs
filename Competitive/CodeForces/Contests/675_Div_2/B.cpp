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
    for(int i=0;i<n/2;++i){
        for(int j=0;j<m/2;++j){
            vector<int> current;
            current.push_back(mat[i][j]);
            current.push_back(mat[n-i-1][j]);
            current.push_back(mat[i][m-j-1]);
            current.push_back(mat[n-i-1][m-j-1]);
            sort(current.begin(),current.end());
            int mid = current[2];
            int cost = 0;
            for(int k=0;k<current.size();++k){
                cost += abs(mid-current[k]);
            }
            int mid2 = current[1];
            int cost2 = 0;
            for(int k=0;k<current.size();++k){
                cost2 += abs(mid2-current[k]);
            }
            ans += (long long int)min(cost,cost2);
        }
    }

    if(n%2==1){
        sort(mat[(n-1)/2].begin(),mat[(n-1)/2].end());
        int mid = mat[(n-1)/2][m/2];
        int cost = 0;
        for(int i=0;i<m;++i){
            cost += abs(mid-mat[(n-1)/2][i]);
        }
        int cost2 = INT_MAX;
        if(m%2==0){
            int mid2 = mat[(n-1)/2][m/2-1];
            cost2 = 0;
            for(int i=0;i<m;++i){
                cost2 += abs(mid2-mat[(n-1)/2][i]);
            }
        }
        ans += (long long int)min(cost,cost2);
    }

    if(m%2==1){
        vector<int> tmp;
        for(int i=0;i<n;++i){
            tmp.push_back(mat[i][m/2]);
        }
        sort(tmp.begin(),tmp.end());
        int cost = 0,cost2 = INT_MAX;
        int mid = tmp[n/2];
        for(int i=0;i<tmp.size();++i){
            cost += abs(mid-tmp[i]);
        }
        if(n%2==0){
            cost2 = 0;
            int mid2 = tmp[n/2-1];
            for(int i=0;i<tmp.size();++i){
                cost2 += abs(mid2-tmp[i]);
            }
        }
        ans += (long long int)min(cost,cost2);
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
