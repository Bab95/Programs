class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int first_buy = INT_MAX,second_buy = INT_MAX,first_profit = 0,second_profit = 0;

        for(int i=0;i<prices.size();++i){
            first_buy = min(prices[i],first_buy);
            first_profit = max(first_profit,prices[i]-first_buy);
            second_buy = min(second_buy,prices[i]-first_profit);
            second_profit = max(second_profit,prices[i]-second_buy);
        }
        return second_profit;
    }
};
