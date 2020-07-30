class Solution {
public:
    const int m = 1e9+7;
    long power(long int a,long int b){
        long res = 1;
        a = a%m;
        while(b>0){
            if(b&1){
                res = res*a % m;
            }
            b = b>>1;
            a = a*a%m;
        }
        return res;
    }
    int sumSubseqWidths(vector<int>& A) {
        if(A.size()==1){
            return 0;
        }
        sort(A.begin(),A.end());
        int n = A.size();
        vector<long int> arr(n-1,0);
        for(int i=0;i<arr.size();++i){
            arr[i] = power(2,i);
        }
        long ans = 0;
        vector<long int> brr(n-1,0);
        int l = 0;
        int r = n-1;
        int k = 1;
        brr[0] = A[r--]-A[l++];

        while(k<n-1){
            brr[k] = brr[k-1] + A[r]-A[l];
            if(brr[k]>m){
                brr[k] = brr[k]%m;
            }
            l++;
            r--;
            k++;
        }

        for(int i=0;i<arr.size();++i){
            ans = ans + arr[arr.size()-i-1]*brr[i]%m;
            ans = ans%m;
        }
        return ans;
    }
};
