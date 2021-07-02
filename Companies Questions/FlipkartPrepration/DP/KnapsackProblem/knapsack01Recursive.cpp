#include <bits/stdc++.h>
using namespace std;
int knapsack(vector<int>& weight,vector<int>& value,int w,int n){
    if(n<0||w==0){
        return 0;
    }
    if(weight[n]>w){
        return knapsack(weight,value,w,n-1);
    }else{
        return max(value[n]+knapsack(weight,value,w-weight[n],n-1),knapsack(weight,value,w,n-1));
    }
    return 0;
}
int main(){
    vector<int> weight,value;
    int n,w;
    cin>>n>>w;
    weight.assign(n,0);
    value.assign(n,0);
    for(int i=0;i<n;++i){
        cin>>weight[i];
    }
    for(int i=0;i<n;++i){
        cin>>value[i];
    }
    cout<<knapsack(weight,value,w,n-1);
}