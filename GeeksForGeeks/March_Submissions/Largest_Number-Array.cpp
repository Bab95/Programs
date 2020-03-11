#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
bool mycompare(string r,string s){
  string x = r.append(s);
  string y = s.append(r);
  return x.compare(y)>0?1:0;
}
int main(){
    int t;
    cin>>t;
    while(t--){
      int n;
      cin>>n;
      vector<string> input(n);
      for(int i=0;i<n;i++){
        cin>>input[i];
      }
      sort(input.begin(),input.end(),mycompare);
      for(int i=0;i<n;i++){
        cout<<input[i];
      }
      cout<<endl;
    }
}
