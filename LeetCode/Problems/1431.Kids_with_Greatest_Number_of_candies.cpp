class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int current_max = INT_MIN;
        for(int i=0;i<candies.size();++i){
            current_max = max(current_max,candies[i]);
        }
        vector<bool> ans(candies.size(),false);
        for(int i=0;i<candies.size();++i){
            if(candies[i]+extraCandies>=current_max){
                ans[i] = true;
            }
        }
        return ans;
    }
};
