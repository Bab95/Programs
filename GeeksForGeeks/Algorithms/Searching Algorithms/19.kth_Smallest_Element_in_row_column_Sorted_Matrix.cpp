#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <list>
#include <string.h>

using namespace std;
#define fo(i,l,r) for(int i=l;i<=r;i++)
#define fi(i,r,l) for(int i=r;i>=l;i--)
#define pb push_back
#define po pop_back
#define INF 1e9+9
void input(vector<int>& arr,int n){
  fo(i,0,n-1){
    cin>>arr[i];
  }
}
struct node{
    int val;
    int row;
    int col;
    node(int v,int r,int c):val(v),row(r),col(c){
    }
};
struct comparator{
    bool operator()(struct node const& s1,struct node const& s2){
        return s1.val>s2.val;
        //min heap...
    }
};
void solve(){
  int m,n,k;
  cin>>m>>n>>k;
  vector<vector<int> > matrix(m,vector<int>(n));
  fo(i,0,m-1){
    input(matrix[0],n);
  }
  priority_queue<node,vector<node>,comparator> pq;
  struct node nnode(0,0,0);
  fo(i,0,m-1){
    nnode.val = matrix[i][0];
    nnode.row = i;
    nnode.col = 0;
    pq.push(nnode);
  }
  int i = 0;
  while(!pq.empty()i<k-1){
      ++i;
      nnode = pq.top();
      pq.pop();
      if(nnode.col<matrix.size()-1){
          nnode.val = matrix[nnode.row][nnode.col+1];
          nnode.col += 1;
          pq.push(nnode);
        }
    }
    int ans = pq.top().val;
    cout<<ans<<endl;
}
int main(){
  int t;
  cin>>t;
  while(t--){
      solve();
  }
  return 0;
}
