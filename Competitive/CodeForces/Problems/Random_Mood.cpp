#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <list>
#include <string.h>
using namespace std;
#define fo(i,l,r) for(int i=l;i<=r;++i)
#define fi(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back
#define po pop_back
#define INF 1e9+9
void input(vector<int>& arr,int n){
  fo(i,0,n-1){
    cin>>arr[i];
  }
}
double power(double p,int n){
    if(n==1){
        return (1.0-p);
    }
    if(n%2==1){
        double result = p
    }
    return 0;
}
void solve(){
  int n;
  cin>>n;
  double p;
  cout<<power(p,n);
int main(){
  solve();
  return 0;
}
