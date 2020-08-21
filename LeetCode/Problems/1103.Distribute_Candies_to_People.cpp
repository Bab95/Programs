class Solution {
public:
    vector<int> distributeCandies(int candies, int n) {
        if(n==1){
            return {candies};
        }
        int i = 1;
        vector<int> ans(n,0);
        while(candies>0){
            ans[(i-1)%n] += min(i,candies);
            candies -= i;
            i += 1;
        }
        return ans;
    }
};
