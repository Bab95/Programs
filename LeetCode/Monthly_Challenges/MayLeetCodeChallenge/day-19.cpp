class StockSpanner {
public:
    vector<int> prices;
    int index;
    StockSpanner() {
        index = 0;
    }

    int next(int price) {
        if(index==0){
            prices.push_back(price);
            index++;
            return 1;
        }else{
            int i = index-1;
            int ans = 1;
            while(i>=0&&prices[i]<=price){
                ans++;
                i--;
            }
            prices.push_back(price);
            index++;
            return ans;
        }
        return 1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
