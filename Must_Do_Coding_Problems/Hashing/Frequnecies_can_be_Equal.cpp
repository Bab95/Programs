#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <string.h>
using namespace std;
bool allsame(int hash_alphabet[]){
    int same;
    int i = 0;
    for(i=0;i<26;i++){
        if(hash_alphabet[i]>0){
            same = hash_alphabet[i];
            break;
        }
    }
    for(int j=i+1;j<26;j++){
        if(hash_alphabet[j]>0&&hash_alphabet[j]!=same){
            return false;
        }
    }
    return true;
}
bool solve(){
  string s1;
  cin>>s1;
  int hash_alphabet[26];
  memset(hash_alphabet,0,sizeof(hash_alphabet));
  for(int i=0;i<s1.length();i++){
      hash_alphabet[s1[i]-'a']++;
  }
  if(allsame(hash_alphabet)){
      return true;
  }else{
      for(int i=0;i<26;i++){
          if(hash_alphabet[i]>0){
              hash_alphabet[i]--;
              if(allsame(hash_alphabet)){
                  return true;
              }
              hash_alphabet[i]++;
          }
      }
  }
  return false;

}
int main(){
    int t;
    cin>>t;
    while(t--){
        if(solve()){
            cout<<"1"<<endl;
        }else{
            cout<<"0"<<endl;
        }
    }
}
