#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef unsigned long long int ulli;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin>>t;
    while(t--){
        ulli n;
        scanf("%llu",&n);
        ulli a = 0;
        ulli b = 1;
        ulli ans = 0;
        while(true){
            ulli c = a+b;
            if(c>n){
                break;
            }
            if(c%2==0){
                ans += c;
            }
            a = b;
            b = c;
        }
        printf("%llu\n",ans);
    }
    return 0;
}
