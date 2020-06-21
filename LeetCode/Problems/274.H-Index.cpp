class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int ans = 0;
        int n = citations.size();
        for(int i=0;i<n;++i){
            int val = citations[i];
            if(n-i<=val){
                ans = max(ans,n-i);
            }
        }
        return ans;
    }
};
