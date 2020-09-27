#include <iostream>
#include <vector>
using namespace std;
int findSubstring(string& s,int start,int end,int k){
    vector<int> hash(26,0);
    for(int i=start;i<=end;++i){
        hash[s[i]-'a']+=1;
    }
    for(int i=0;i<26;++i){
        if(hash[i]&&hash[i]==k){
            return end-start+1;
        }
    }
    int left,right;
    for(int i=start;i<=end;++i){
        if(hash[s[i]]!=k){
            left = findSubstring(s,left,i,k);
            right = findSubstring(s,i+1,end,k);
            return max(left,right);
        }

    }
    return 0;
}
void solve(){
    string s;
    cin>>s;
    int k;
    cin>>k;
    int start = 0;
    int end = s.length()-1;
    int len = findSubstring(s,start,end,k);
}
int main(){
    int t;
    cin>>t;
    while(t-- ){
        solve();
    }
}
