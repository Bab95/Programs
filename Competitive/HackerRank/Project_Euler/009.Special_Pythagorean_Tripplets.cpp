#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        long long int ans = -1;
        for(int a=1;a<=n/3;++a){
            int b = (n*n-2*n*a)/(2*n-2*a);
            int c = n-a-b;
            //cout<<a<<" "<<b<<" "<<c<<endl;
            if(a*a+b*b==c*c){
                long long int product = a*b*c;
                ans = (long long int)max(ans,product);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
