#define M 1000000007
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int N = (n*(n+1))/2;
        vector<int> arr;
        arr.reserve(N);
        vector<int> prefix(n+1,0);
        for(int i=0;i<n;++i){
            prefix[i+1] = prefix[i] + nums[i];
        }
        for(int start=0;start<n;++start){
            for(int end=start+1;end<=n;++end){
                int current = prefix[end] - prefix[start];
                arr.push_back(current);
            }
        }
        sort(arr.begin(),arr.end());
        long int ans = 0;
        for(int i=left-1;i<=right-1;++i){
            ans += arr[i];
        }
        return ans%M;
    }
};
