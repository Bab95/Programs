#include <iostream>
#include <string>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    string input;
    cin>>input;
    int l = 0,r=input.length()-1;
    while(input[l]=='0'&&l<=r){
      l++;
    }
    while(input[r]=='0'&&r>=l){
      r--;
    }
    int min_count = 0;
    if(l>=r){
      cout<<min_count<<endl;
    }else{
      int longest_ones = 0;
      for(int i=l;i<=r;i++){
        if(input[i]=='0'){
          min_count++;
        }
      }
      cout<<min_count<<endl;
    }
  }
}
