#include <iostream>
#include <math.h>
using namespace std;
int main(){
  int l;
  cin>>l;
  int leaf_sum = 0;
  int n = (int)pow(2,l-1);
  for(int i=1;i<=n;i++){
    leaf_sum+=i;
  }
  cout<<leaf_sum*l<<endl;
}
