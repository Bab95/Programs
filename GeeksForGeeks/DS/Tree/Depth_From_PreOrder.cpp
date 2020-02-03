#include <iostream>
using namespace std;
int max(int a,int b){
  return a>b?a:b;
}
int depth(char tree[],int n,int &index){
  if(index>=n||tree[index]=='l'){
    return 0;
  }
  index++;
  int left = depth(tree,n,index);
  index++;
  int right = depth(tree,n,index);
  return max(left,right)+1;
}
int findDepth(char tree[],int n){
  int index = 0;
  return depth(tree,n,index);
}
int main(){
  char tree[]="nlnnlll";
  int n = sizeof(tree)/sizeof(char);
  cout<<findDepth(tree,n)<<endl;
}
