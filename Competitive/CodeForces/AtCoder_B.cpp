#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <unordered_map>
#include <map>
#include <limits.h>
#include <unordered_set>
#include <stack>
#include <string.h>
#define fo(i,l,r) for(int i=l;i<=r;++i)
#define fi(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back
#define po pop_back
using namespace std;
const int M (int)10e6;
std::bitset<M+1> bits;
void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void input(vector<int>& arr,int n){
    fo(i,0,n-1){
        cin>>arr[i];
    }
}
void print(vector<int>& ans,int n){
    fo(i,0,n-1){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
void solve(){
    int n;
    cin>>n;
    double sum=0;
    fo(i,3,n){
        if(bits[i]==1){
            sum+=i;
        }
    }
    cout<<sum<<endl;
}
void generate(){
    fo(i,M,++i){
        if(i%3==0||i%5==0){
            bits[i] = 1;
        }else{
            bits[i] = 0;
        }
    }
}
int main(){
    generate();
    solve();
}