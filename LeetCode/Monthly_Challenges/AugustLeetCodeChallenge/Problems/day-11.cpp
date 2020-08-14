class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int n = citations.size();
        int ans = 0;
        for(int i=0;i<citations.size();++i){
            int val = citations[i];
            if(n-i<=val){
                ans = max(ans,n-i);
            }
        }
        return ans;
    }
};
