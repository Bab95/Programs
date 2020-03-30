// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int maxLen(int A[], int n);

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];
        cout << maxLen(A, N) << endl;
    }
}
// } Driver Code Ends
/*You are required to complete this function*/
int maxLen(int A[], int n) {
    // Your code here
    /*unordered_map<int,vector<int> > my_map;
    vector<int> sum(n,0);
    sum[0] = A[0];
    my_map[sum[0]].push_back(0);
    for(int i=1;i<n;i++){
        sum[i] = sum[i-1]+A[i];
        my_map[sum[i]].push_back(i);
    }
    unordered_map<int,vector<int> >::iterator itr;
    int max_length = 0;
    for(itr=my_map.begin();itr!=my_map.end();itr++){
        if(itr->first==0){
            int current_length = itr->second[itr->second.size()-1] + 1;
            max_length = max(current_length,current_length);
        }else if(itr->second.size()>1){
            int current_length = itr->second[itr->second.size()-1]-itr->second[0];
            if(current_length>max_length){
                max_length = current_length;
            }
        }
    }
    return max_length;*/
    unordered_map<int,vector<int> > my_map;
    //vector<int> sum(n,0);
    int sum = 0;
    int result = 0;
    for(int i=0;i<n;i++){
        sum += A[i];
        if(A[i]==0&&result==0){
            result = 1;
        }
        if(sum==0){
            result = i+1;
        }
        my_map[sum].push_back(i);
    }
    unordered_map<int,vector<int> >::iterator itr;
    for(itr=my_map.begin();itr!=my_map.end();itr++){
        result = max(result,*(itr->second.end()-1)-*(itr->second.begin()));
    }
    return result;
}
