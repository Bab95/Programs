#include <bits/stdc++.h>
using namespace std;
/*
Solution: check for each length taking i as start and j as end points
(i+1 to j-1) must be a palindrome for (i to j) to be palindrome.
*/
void solve(){
    string s;
    cin>>s;
    vector<vector<int> > dp(s.length(),vector<int>(s.length(),false));
    for(int i=0;i<s.length();++i){
        dp[i][i] = true;
    }
    int max_len = -1;
    int start = -1;
    for(int i=0;i<s.length()-1;++i){
        if(s[i]==s[i+1]){
            dp[i][i+1] = true;
            if(max_len<2){
                start = i;
                max_len = 2;
            }
        }
    }
    
    for(int k=3;k<=s.length();++k){
        for(int i=0;i<s.length()-k+1;++i){
            int j = i + k - 1;
            if(s[i]==s[j]&&dp[i+1][j-1]==true){
                dp[i][j] = true;
                if(k>max_len){
                    max_len = k;
                    start = i;
                }
            }
        }
    }
    if(start==-1){
        cout<<s[0]<<endl;
        return;
    }
    cout<<s.substr(start,max_len)<<endl;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    solve();
	}
	return 0;
}