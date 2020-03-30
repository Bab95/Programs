#include <bits/stdc++.h>
using namespace std;
int mod(int a,int b){
  int res = a-b;
  if(res<0){
    return -1*res;
  }
  return res;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin>>s;
  int a=0,b=0,c=0;
  int i = 0;
  while(s[i]!='+'){
    ++a;
    ++i;
  }
  ++i;
  while(s[i]!='='){
    ++b;
    ++i;
  }
  ++i;
  for(;i<s.length();++i){
    ++c;
  }
  if(a+b==c){
    cout<<s<<endl;
  }else if(mod(a+b,c)!=2){
    cout<<"Impossible"<<endl;
  }else{
    if(a+b>c){
      c++;
      if(a>b){
        a--;
      }else{
        b--;
      }
    }else{
      a++;
      c--;
    }
    char result[s.length()+1];
    i = 0;
    while(a--){
      result[i++] = '|';
    }
    result[i++] = '+';
    while(b--){
      result[i++] = '|';
    }
    result[i++] = '=';
    while(c--){
      result[i++] = '|';
    }
    result[i] = '\0';
    cout<<result<<endl;

  }
}
