#include <iostream>
using namespace std;
int NoOfTrees(int n){
  int tree[n+1];
  for(int i=0;i<=n;i++){
    tree[i] = 0;
  }
  tree[0] = 1;
  tree[1] = 1;
  for(int i=2;i<=n;i++){
    for(int j=0;j<i;j++){
      tree[i] += tree[j]*tree[i-j-1];
    }
  }
  return tree[n];
}
int main(){
  int n;
  cin>>n;
  cout<<NoOfTrees(n);
}
