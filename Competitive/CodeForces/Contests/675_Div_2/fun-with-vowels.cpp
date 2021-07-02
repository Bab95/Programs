#include <bits/stdc++.h>
using namespace std;
int find_max_length_vowel_subsequence(string& s){
    unordered_map<char,int> mmap;
    mmpa['a'] = 0;
    mmap['e'] = 0;
    mmap['i'] = 0;
    mmap['o'] = 0;
    mmap['u'] = 0;
    int ans = 0;
    int tt = 0;
    while(tt<s.length()&&s[tt]!='a'){
        tt++;
    }
    for(int i=tt;i<s.length();++i){
        char current = s[i];
        if(current=='a'){
            mmap[current]++;
        }else if(current=='e'){
            mmap[current] = max(mmap['a'],mmap['e']])+1;
        }else if(current=='i'){
            mmap[current] = max(mmap['e'],mmap['i'])+1;
        }else if(current=='o'){
            mmap[current] = max(mmap[current],mmap['i']) + 1;
        }else if(current=='u'){
            mmap[current] = max(mmap[current],mmap['o']) + 1;
        }
    }
    return mmap['u'];
}
void solve(){
    string s;
    cin>>s;
    cout<<find_max_length_vowel_subsequence(s);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}