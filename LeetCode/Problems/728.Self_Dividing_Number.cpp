class Solution {
public:
    bool sdn(int n){
        int x = n;
        while(n){
            int d = n%10;
            if(d==0){
                return false;
            }
            if(x%d!=0){
                return false;
            }
            n = n/10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i=left;i<=right;++i){
            if(sdn(i)){
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};
