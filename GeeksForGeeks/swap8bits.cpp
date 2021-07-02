#include <bits/stdc++.h>
using namespace std;
void solve(uint32_t& a,uint32_t& b){
  uint32_t mask = 0x0000FF00;
  uint32_t _mask = 0xFFFF00FF;
  uint32_t a_bits = a & mask;
  uint32_t b_bits = b & mask;
  a &= _mask;
  a |= b_bits;
  b |= a_bits;
}
int main(){
  uint32_t a,b;
  cin>>a>>b;
  solve(a,b);
  cout<<a<< " " <<b<<endl;
  return 0;
}
