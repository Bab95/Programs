#include <bits/stdc++.h>
using namespace std;
#define speed ios::sync_with_stdio(0);cin.tie(0)
typedef long long int ll;
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
int strStr(string& haystack, string& needle,vector<int>& lps) {
    int needle_length = needle.length();
    if(needle_length==0){
        return 0;
    }
    //vector<int> lps(needle_length);
    //calculateLps(needle_length,lps,needle);
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
    int n,k;
    cin>>k>>n;
    vector<string> fav(k);
    vector<string> s(n);
    vector<vector<int> > lps;
    for(int i=0;i<k;++i){
        //scanf("%s",fav[i]);
        cin>>fav[i];
        vector<int> tmp(fav[i].length());
        calculateLps(fav[i].length(),tmp,fav[i]);
        lps.push_back(tmp);
    }
    for(int i=0;i<n;++i){
        //scanf("%s",s[i]);
        cin>>s[i];
    }
    for(int i=0;i<n;++i){
        if(s[i].length()>=47){
            cout<<"Good"<<endl;
        }else{
            bool good = false;
            for(int j=0;j<k;++j){
                int needle = strStr(s[i],fav[j],lps[j]);
                if(needle!=-1){
                    cout<<"Good"<<endl;
                    good = true;
                    break;
                }
            }
            if(!good){
                cout<<"Bad"<<endl;
            }
        }
    }
}
int main(){
    speed;
    solve();
}
