#include <iostream>
using namespace std;
int main(){
  int t,n;
  cin>>t;
  while(t--){
    cin>>n;
    long long int ways[n+1];
    ways[0] = 1;
    ways[1] = 1;
    ways[2] = 2;
    for(int i=3;i<=n;i++){
        ways[i] = ways[i-1]+ways[i-2];
    }
    cout<<ways[n]<<endl;
  }
  return 0;
}
