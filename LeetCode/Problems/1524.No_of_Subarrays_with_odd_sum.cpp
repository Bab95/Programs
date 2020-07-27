class Solution {
public:
    const int m = 1000000007;
    int numOfSubarrays(vector<int>& arr) {
        vector<long int> prefix(arr.size(),0);
        prefix[0] = arr[0];
        long long int odd = 0;
        long long int even = 0;
        if(prefix[0]%2==0){
            even++;
        }else{
            odd++;
        }
        for(int i=1;i<arr.size();++i){
            prefix[i] = prefix[i-1] + arr[i];
            if(prefix[i]%2==0){
                even++;
            }else{
                odd++;
            }
        }
        long long int ans = odd + (odd*even);
        ans = ans%m;
        return ans;
    }
};
