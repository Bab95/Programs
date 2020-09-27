#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve(){
    int len;
    string s;
    cin>>len;
    cin>>s;
    if(len==1){
        cout<<-1<<endl;
        return;
    }
    vector<vector<int> > dp(len+1,vector<int>(len+1,0));
    int index = 0;
    int max_length = INT_MIN;
    for(int i=1;i<=len;++i){
        for(int j=i+1;j<=len;++j){
            if(s[i-1]==s[j-1]&&dp[i-1][j-1]+i<j){
                dp[i][j] = dp[i-1][j-1] + 1;
                if(dp[i][j]>max_length){
                    index = max(i,index);
                    max_length = dp[i][j];
                }
            }else{
                dp[i][j] = 0;
            }
        }
    }
    if(max_length==0){
        cout<<-1<<endl;
    }else{
        for(int i=index-max_length;i<index;++i){
            cout<<s[i];
        }
        cout<<endl;
    }
    //for(int i=0;i<=len;++i){
    //    for(int j=0;j<=len;++j){
    //        cout<<dp[i][j]<<" ";
    //    }
    //    cout<<endl;
    //}
    //cout<<index<< " "<<max_length<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t-- ){
        solve();
    }
}

/*
1
8
-2 -3 4 -1 -2 1 5 -3
 */
