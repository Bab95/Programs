#include <bits/stdc++.h>
using namespace std;
void calculateLps(int m,vector<int> &lps,string needle){
    int i = 1;
    lps[0] = 0;
    int j = 0;
    while(i<m){
        if(needle[i]==needle[j]){
            lps[i] = j+1;
            i++;
            j++;
        }else{
            if(j!=0){
                j = lps[j-1];
            }else{
                lps[i] = 0;
                i++;
            }
        }
    }
}
int strStr(string& haystack, string& needle) {
    int needle_length = needle.length();
    if(needle_length==0){
        return 0;
    }
    vector<int> lps(needle_length);
    calculateLps(needle_length,lps,needle);
    int i = 0;
    int j = 0;
    int N = haystack.length();
    int res_index = -1;
    while(i<N){
        if(needle[j]==haystack[i]){
            j++;
            i++;
        }
        if(j==needle_length){
            res_index = i-j;
            break;
        }
        else if(i<N&&needle[j]!=haystack[i]){
            if(j!=0){
                j = lps[j-1];
            }else{
                i+=1;
            }
        }
    }
    return res_index;
}
void solve(){
  string s;
  cin>>s;
  string s1 = "101";
  string s2 = "010";
  if(strStr(s,s1)!=-1||strStr(s,s2)!=-1){
    cout<<"Good";
  }else{
    cout<<"Bad";
  }
  cout<<endl;
}
int main(){
  int t;
  cin>>t;
  while(t--){
    solve();
  }
}
