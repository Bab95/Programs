// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int maxLen(int arr[], int n);

int main()
{
    // your code goes here
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << maxLen(a, n) << endl;
    }
    return 0;
}// } Driver Code Ends


/*You are required to complete this method*/

// arr[] : the input array containing 0s and 1s
// N : size of the input array

// return the maximum length of the subarray
// with equal 0s and 1s
int maxLen(int arr[], int N)
{
    // Your code here
    unordered_map<int,int> mmap;
    int sum = 0;
    int len = -1;
    for(int i=0;i<N;++i){
        if(arr[i]==1){
            sum += 1;
        }else{
            sum-=1;
        }
        if(sum==0){
            len = i+1;
        }else{
            if(mmap.find(sum)!=mmap.end()){
                len = max(len,i-mmap[sum]);
            }else{
                mmap[sum] = i;
            }
        }
    }
    return max(len,0);
}
