class Solution {
public:
    int kadane(vector<int>& arr,int sign){
        int ans = arr[0]*sign;
        int current = ans;
        for(int i=1;i<arr.size();++i){
            current = max(current+sign*arr[i],arr[i]*sign);
            ans = max(current,ans);
        }
        return ans;
    }
    int maxSubarraySumCircular(vector<int>& A) {
        //normal case for non circular.....
        int ans1 = kadane(A,1);
        int ans2 = kadane(A,-1);
        int sum = 0;
        for(int i=0;i<A.size();++i){
            sum+=A[i];
        }
        ans2 = sum+ans2;
        if(ans2==0){
            return ans1;
        }
        return max(ans1,ans2);

    }
};
