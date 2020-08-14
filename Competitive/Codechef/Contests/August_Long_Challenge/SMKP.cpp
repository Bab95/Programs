#include <bits/stdc++.h>
using namespace std;
void solve(){
	string s,p;
	cin>>s>>p;
	unordered_map<char,int> mmap;
	for(int i=0;i<s.length();++i){
		mmap[s[i]] += 1;
	}
	for(int i=0;i<p.length();++i){
		mmap[p[i]] -= 1;
	}
    vector<pair<char,int> > chars;
    for(auto it = mmap.begin(); it != mmap.end(); ++it){
        if(it->second>0){
            chars.push_back({it->first,it->second});
        }
    }
    sort(chars.begin(),chars.end());
    string ans;
    int i = 0;
    for(i=0;i<chars.size();++i){
        if(chars[i].first>=p[0]){
            break;
        }
        for(int k=0;k<chars[i].second;++k){
            ans.push_back(chars[i].first);
        }
    }
    if(i==chars.size()){
        int k = 0;
        while(k<p.length()){
            ans.push_back(p[k]);
            k++;
        }
        cout<<ans<<endl;
        return;
    }else{
        int j = 0;
        while(j<p.length() && p[j]==chars[i].first){
            ans.push_back(p[j]);
            j++;
        }
        if(j<p.length()){
            if(p[j]<chars[i].first){
                while(j<p.length()){
                    ans.push_back(p[j]);
                    j++;
                }
            }else if(p[j]>chars[i].first){
                int k = 0;
                while(k<chars[i].second){
                    ans.push_back(chars[i].first);
                    k++;
                }
                i++;
                while(j<p.length()){
                    ans.push_back(p[j]);
                    j++;
                }
            }
        }
        //fill rest....
        while(i<chars.size()){
            for(int k=0;k<chars[i].second;++k){
                ans.push_back(chars[i].first);
            }
            ++i;
        }
        cout<<ans<<endl;
    }
}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}
