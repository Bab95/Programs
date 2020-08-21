#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
void solve(){
    unordered_map<char,int> mmap;
    int x1,y1;
    int q;
    string s;
    cin>>s;
    cin>>x1>>y1;
    cin>>q;
    for(int i=0;i<s.length();++i){
        mmap[s[i]] += 1;
    }
    int x2,y2;
    while(q--){
        cin>>x2>>y2;
        int left_right = x2-x1;
        int up_down = y2-y1;
        bool f1 = false,f2 = false;
        int steps = 0;
        if(left_right>0){
            if(mmap['R']>=left_right){
                f1 = true;
                steps += left_right;
            }else{
                f1 = false;
            }
        }else{
            if(mmap['L']>=abs(left_right)){
                f1 = true;
                step += abs(left_right);
            }else{
                f1 = false;
            }
        }

        if(up_down>0){
            if(mmap['U']>=up_down){
                f2 = true;
                steps+=abs(up_down);
            }else{
                f2 = false;
            }
        }else{
            if(mmap['D']>=abs(up_down)){
                f2 = true;
                steps+=abs(up_down);
            }else{
                f2 = false;
            }
        }
        if(f1&&f2){
            cout<<"YES"<<" "<<steps<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}
int main(){
    int t;
    speed;
    cint>>t;
    while(t--){
        solve();
    }
}