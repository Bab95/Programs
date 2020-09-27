#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int i,int j,int n,vector<string> &result,string s){
        if(s.length()==2*n){
            result.push_back(s);
            return;
        }
        if(i<n){
            s.push_back('(');
            dfs(i+1,j,n,result,s);
            s.pop_back();
        }
        if(j<i){
            s.push_back(')');
            dfs(i,j+1,n,result,s);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string s;
        dfs(0,0,n,result,s);
        return result;
    }
};
int main(){
    Solution *obj = new Solution();
    vector<string> ans = obj->generateParenthesis(3);
    for(auto it : ans){
        cout<<it<<endl;
    }
    return  0;
}