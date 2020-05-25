class Solution {
public:
    int kadane(vector<int>& arr,int sign){
        int ans = arr[0]*sign;
        int current_max = arr[0]*sign;
        for(int i=1;i<arr.size();++i){
            current_max = max(current_max+arr[i]*sign,arr[i]*sign);
            ans = max(current_max,ans);
        }
        return ans;
    }
    int maxSubarraySumCircular(vector<int>& arr) {
        //first circular sum...Normal_case....
        int ans1 = kadane(arr,1);
        int ans2 = kadane(arr,-1);
        int sum = 0;
        for(int i=0;i<arr.size();++i){
            sum += arr[i];
        }
        ans2 = sum+ans2;
        if(ans2==0){
            return ans1;
        }
        return max(ans1,ans2);

    }
};
