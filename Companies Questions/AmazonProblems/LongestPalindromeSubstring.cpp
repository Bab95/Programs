#include <iostream>
#include <string>
#include <string.h>
using namespace std;
void printsubstring(int start,int length,string s){
    for(int i=start;i<start+length;i++){
        cout<<s[i];
    }
    cout<<endl;
}
int main() {
	//code
	int t;
	cin>>t;
	string s;
	while(t--){
	    cin>>s;
	    int n = s.length();
	    bool dp[n][n];
	    memset(dp,0,sizeof(dp));
	    for(int i=0;i<n;i++){
	        dp[i][i] = true;
	    }
	    int start = -1;
	    int length = 0;
	    for(int i=0;i<n-1;i++){
	        if(s[i]==s[i+1]){
	            dp[i][i+1] = true;
	            start = (start==-1)?i:start;
	            length = 2;
	        }
	    }
	    for(int k=3;k<=n;k++){
	        for(int i=0;i<n-k+1;i++){
	            int j = i+k-1;
	            if(dp[i+1][j-1]==true&&s[i]==s[j]){
	                dp[i][j] = true;
	                if(k>length){
	                    length = k;
	                    start = i;
	                }
	            }
	        }
	    }
	    if(start!=-1)
	        printsubstring(start,length,s);
	    else
	        cout<<s[0]<<endl;
	}
	return 0;
}
