#include <bits/stdc++.h>
using namespace std;
int main(){
  long long int a;
  cin>>a;
  long long int s1 = 1,s2=3,s3=6;
  if(a<s1){
    cout<<"no"<<endl;
    return 0;
  }
  else if(a==s1||a==s2||a==s3){
    cout<<"yes"<<endl;
    return 0;
  }
  else{
    int n1 = (a-s1)%6;
    int n2 = (a-s2)%6;
    int n3 = (a-s3)%6;
    if(n1==0||n2==0||n3==0){
      cout<<"yes"<<endl;
    }else{
      cout<<"no"<<endl;
    }
  }
  return 0;
}
