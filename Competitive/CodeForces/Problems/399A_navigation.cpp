#include <iostream>
using namespace std;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,p,k;
  cin>>n>>p>>k;
  if(p>=1&&p<=n){
    int start = max(p-k,1);
    int end = min(p+k,n);
    bool f1,f2;
    f1 = (start==1)?false:true;
    f2 = (end==n)?false:true;
    if(f1){
      cout<<"<< ";
    }
    for(int i=start;i<=end;++i){
      if(i==p){
        cout<<"("<<i<<") ";
      }else
        cout<<i<<" ";
    }
    if(f2){
      cout<<">>";
    }
    cout<<endl;
  }
  return 0;
}
