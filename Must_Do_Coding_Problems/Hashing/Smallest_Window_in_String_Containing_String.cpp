#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <limits.h>
using namespace std;
void solve(){
  string s1,s2;
  cin>>s1;
  cin>>s2;
  unordered_map<char,int> hash2;
  for(int i=0;i<s2.length();i++){
      hash2[s2[i]] += 1;
  }
  int start_index = -1;
  int i = 0;
  int len = s2.length();
  int min_length = INT_MAX;
  int start = 0;
  unordered_map<char,int> hash;
  while(i<s1.length()){
      hash[s1[i]]++;
      if(hash2[s1[i]]>0&&hash[s1[i]]<=hash2[s1[i]]){
          len--;
      }
      if(len==0){
          while(hash[s1[start]]>hash2[s1[start]]||hash[s1[start]]==0){
              if(hash[s1[start]]>hash2[s1[start]]){
                  hash[s1[start]]--;
              }
              start++;
          }
          int current = i-start+1;
          if(current<min_length){
              min_length = current;
              start_index = start;
          }
      }
      i++;
  }
  //cout<<start_index<<endl;
  if(start_index!=-1){
      for(int i=start_index;i<start_index+min_length;i++){
          cout<<s1[i];
      }
      cout<<endl;
  }else{
      cout<<"-1"<<endl;
  }


}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
