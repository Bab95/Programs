#include <iostream>
#include <string.h>
using namespace std;
unsigned long long int min(unsigned long long int a,unsigned long long int b,unsigned long long int c){
    return (a<b)?((a<c)?a:c):((b>c)?c:b);
}
int main() {
	//code
	int t;
	unsigned long long int n;
	cin>>t;
	while(t--){
	   cin>>n;
	   unsigned long long int ugly[n];
	   memset(ugly,0,sizeof(ugly));
	   ugly[0] = 1;
	   unsigned long long int index_2 = 0;
	   unsigned long long int index_3 = 0;
	   unsigned long long int index_5 = 0;
	   unsigned long long int next_2 = 2;
	   unsigned long long int next_3 = 3;
	   unsigned long long int next_5 = 5;
	   unsigned long long int next_ugly = 1;
	   for(unsigned long long int i=1;i<n;i++){
	       next_ugly = min(next_2,next_3,next_5);
	       ugly[i] = next_ugly;
	       if(next_ugly==next_2){
	           index_2++;
	           next_2 = ugly[index_2]*2;
	       }
	       if(next_ugly==next_3){
	           index_3++;
	           next_3 = ugly[index_3]*3;
	       }
	       if(next_ugly==next_5){
	           index_5++;
	           next_5 = ugly[index_5]*5;
	       }
	   }
	   /*for(int i=0;i<n;i++){
	       cout<<ugly[i]<<" ";
	   }
	   cout<<endl;
	   */cout<<ugly[n-1]<<endl;
	}
	return 0;
}
