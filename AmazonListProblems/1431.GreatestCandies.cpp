class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxcandies = candies[0];
        vector<bool> result(candies.size(), false);
        for(int i=1;i<candies.size();i++){
            maxcandies = max(candies[i], maxcandies);
        }
        
        for (int i=0;i<candies.size();i++){
            if (candies[i] + extraCandies >= maxcandies){
                result[i] = true;
            }
        }
        return result;
    }
};