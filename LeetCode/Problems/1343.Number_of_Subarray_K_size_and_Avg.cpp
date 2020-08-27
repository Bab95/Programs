class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum = 0;
        for(int i=0;i<k;++i){
            sum += arr[i];
        }
        int ans = 0;
        for(int i=k;i<arr.size();++i){
            if(sum/k>=threshold){
                ans++;
            }
            sum += arr[i];
            sum -= arr[i-k];
        }
        if(sum/k>=threshold){
            ans++;
        }
        return ans;
    }
};
