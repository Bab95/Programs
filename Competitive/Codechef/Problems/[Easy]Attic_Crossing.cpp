#include <bits/stdc++.h>
using namespace std;
void solve(){
    string s;
    cin>>s;
    int max_jump = 0;
    int days = 0;
    for(int i=0;i<s.length();){
        if(s[i]=='#'){
            i++;
        }else if(s[i]=='.'){
            int count = 0;
            while(i<s.length()&&s[i]=='.'){
                ++count;
                ++i;
            }
            if(count>max_jump){
                days++;
                max_jump = count;
            }
        }
    }
    cout<<days<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
