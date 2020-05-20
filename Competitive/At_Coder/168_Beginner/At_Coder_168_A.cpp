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
void solve(){
  int n;
  cin>>n;
  int last = n%10;
  if(last==2||last==4||last==5||last==7||last==9){
    cout<<"hon";
  }else if(last==0||last==1||last==6||last==8){
    cout<<"pon";
  }else{
    cout<<"bon";
  }
  cout<<endl;
}
int main(){
  solve();
  return 0;
}
