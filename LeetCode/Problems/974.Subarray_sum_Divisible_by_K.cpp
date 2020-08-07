class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        if(A.size()==0){
            return 0;
        }
        if(A.size()==1){
            if(A[0]%K!=0){
                return 0;
            }else{
                return 1;
            }
        }
        int sum = 0;
        unordered_map<int,int> mmap;
        mmap[0] = 1;
        int ans = 0;
        for(int i=0;i<A.size();++i){
            sum += A[i];
            int rem = sum%K;
            if(rem<0){
                rem += K;
            }
            if(mmap.find(rem)!=mmap.end()){
                ans += mmap[rem];
            }
            mmap[rem] += 1;
        }
        return ans;
    }
};
