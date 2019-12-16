#include <bits/stdc++.h>
using namespace std;
struct val{
	int first;
	int second;
};
int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}

		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}
/*You are required to complete this method*/
#include <string.h>
int maxChainLen(struct val p[],int n)
{
//Your code here
    int *dp = new int[n];
    for(int i=0;i<n;i++){
        dp[i] = 1;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(p[j].second<p[i].first&&dp[j]+1>dp[i]){
                dp[i] = dp[j]+1;
            }
        }
    }
    int result = 0;
    for(int i=0;i<n;i++){
        if(dp[i]>result){
            result = dp[i];
        }
    }
    return result;
}
