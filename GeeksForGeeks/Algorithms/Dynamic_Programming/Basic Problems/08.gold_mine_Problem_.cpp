#include <bits/stdc++.h>
using namespace std;

void solve() {
	//code
	int m,n;
	cin>>m>>n;
	vector<vector<int> > mat(m,vector<int>(n));
	for(int i=0;i<m;++i){
	    for(int j=0;j<n;++j){
	        cin>>mat[i][j];
	    }
	}
	for(int j=1;j<n;++j){
	    for(int i=0;i<m;++i){
	        int a = (i>0)?mat[i-1][j-1]:0;
	        int b = mat[i][j-1];
	        int c = (i<m-1)?mat[i+1][j-1]:0;
	        mat[i][j] += max(a,max(b,c));
	    }
	}
	int ans = mat[0][n-1];
	for(int i=1;i<m;++i){
	    ans = max(ans,mat[i][n-1]);
	}
	cout<<ans<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
