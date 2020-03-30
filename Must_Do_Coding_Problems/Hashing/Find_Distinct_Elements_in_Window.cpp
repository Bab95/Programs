// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

void countDistinct(int[], int, int);

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        countDistinct(a, k, n);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
/*You are required to complete below method */
void countDistinct(int arr[], int k, int n) {
    // Your code here
    unordered_map<int,int > mmap;
    for(int i=0;i<k;i++){
        mmap[arr[i]] = mmap[arr[i]] + 1;
    }
    cout<<mmap.size()<<" ";
    for(int i=k;i<n;i++){
        int prev = arr[i-k];
        int next = arr[i];
        mmap[prev]--;
        if(mmap[prev]==0){
            mmap.erase(prev);
        }
        mmap[next] = mmap[next] + 1;
        cout<<mmap.size()<<" ";
    }
}
