#include<bits/stdc++.h>
using namespace std;
long long int floorSqrt(long long int x);

//Position this line where user code will be pasted.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		cout << floorSqrt(n) << endl;
	}
    return 0;
}

/*This is a function problem.You only need to complete the function given below*/

// Function to find square root
// x: element to find square root
#include <limits.h>
long long int floorSqrt(long long int x)
{
    // Your code goes here
    if(x<4){
        return 1;
    }
    for(long long int i=1;i<=x/2+1;i++){
        if(i*i==x){
            return i;
        }
        else if(i*i>x){
            return i-1;
        }
    }
    return INT_MIN;
}
