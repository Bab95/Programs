#include <iostream>
#include <vector>
using namespace std;
void update_Fenwick_Tree(vector<int>& Fenwick_Tree,int i,int delta){
  i+=1;
  while(i<Fenwick_Tree.size()){
    Fenwick_Tree[i]+=delta;
    i += (i&-i);
  }
}
vector<int> construct_Fenwick_Tree(vector<int>& arr){
  vector<int> Fenwick_Tree(arr.size()+1,0);
  for(int i=1;i<=arr.size();++i){
    update_Fenwick_Tree(Fenwick_Tree,i,arr[i]);
  }
  return Fenwick_Tree;
}
int get_Sum(vector<int>& Fenwick_Tree,int i){
  i+=1;
  int sum = 0;
  while(i>0){
    sum += Fenwick_Tree[i];
    i -= (i&-i);
  }
  return sum;
}
int rangeSum(vector<int>& Fenwick_Tree,int a,int b){
  //a upper bound b lower bound.....
  return get_Sum(Fenwick_Tree,a)-get_Sum(Fenwick_Tree,b-1);
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;++i){
      cin>>arr[i];
    }
    vector<int> Fenwick = construct_Fenwick_Tree(arr);
}
