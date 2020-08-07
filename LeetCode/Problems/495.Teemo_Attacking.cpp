class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if(timeSeries.size()==0){
            return 0;
        }
        long long int ans = duration;
        for(int i=1;i<timeSeries.size();++i){
            ans+=duration;
            if(timeSeries[i]<=timeSeries[i-1]+duration){
                int elapsed = duration-max(0,(timeSeries[i]-timeSeries[i-1]));
                ans -= elapsed;
            }
        }
        return ans;
    }
};
