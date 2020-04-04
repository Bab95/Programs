#include <iostream>
#include <vector>
#define M 1000000000 + 7
bool primes[M];
void primecalculate(){
    for(int i=2;i*i<=M;i++){
        if(primes[i]==false){
            for(int k=i*i;i<=M;k+=i){
                primes[k] = true;
            }
        }
    }
}
using namespace std;
int main(){
    primecalculate();
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    return 0;
}