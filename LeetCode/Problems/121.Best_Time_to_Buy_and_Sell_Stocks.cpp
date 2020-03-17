class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_value = INT_MAX;
        int max_profit = 0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<min_value){
                min_value = prices[i];
            }else{
                max_profit = max(max_profit,prices[i]-min_value);
            }
        }
        return max_profit;
    }
};
