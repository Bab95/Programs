#include <iostream>
using namespace std;
int main(){
  int n;
  cin>>n;
  if(n==2||n%2==1){
    cout<<"NO"<<endl;
  }else if(n%2==0){
    cout<<"YES"<<endl;
  }
  return 0;
}
