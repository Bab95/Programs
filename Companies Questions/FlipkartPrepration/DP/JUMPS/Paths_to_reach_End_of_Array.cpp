#include <bits/stdc++.h>
using namespace std;
struct pair{
    string path;
    int index;
    int jumps;
};
void min_jumps(vector<int>& arr,vector<int>& dp,int n){
    fill(dp.begin(),dp.end(),INT_MAX);
    dp[n-1]  = 0;
    for(int i=n-2;i>=0;i--){
        int steps = arr[i];
        int _min = INT_MAX;
        for(int j=1;j<steps&&i+j<n;j++){
            if(dp[i+j]!=INT_MAX&&dp[i+j]<_min){
                _min = dp[i+j];
            }
        }
    }
    if(_min!=INT_MAX){
        dp[i] = _min + 1;
    }
}
void possiblePaths(vector<int>& arr,vector<int>& dp,int n){
    queue<pair> queue;
    pair p1 = {0,"0",dp[0]};
    queue.push(p1);
    while(!queue.empty()){
        pair tmp = queue.front();
        queue.pop();
        if(tmp.jumps==0){
            cout<<tmp.paths<<endl;
            continue;
        }
        for(int step=1;step<=arr[tmp.index];step++){
            if(tmp.index+step<n&&tmp.jump-1==dp[tmp.index+step]){
                string s1 = tmp.path + "-> " + to_string((tmp.index+step));
                pair p2 = {tmp.index+step,s1,tmp.jump-1};
                queue.push(p2);
            }
        }
    }
}
int main(){
    
}