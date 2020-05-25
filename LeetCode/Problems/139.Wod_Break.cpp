class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string> sset;

        int max_length = 0;
        for(int i=0;i<wordDict.size();++i){
            sset.insert(wordDict[i]);
            max_length = max(max_length,(int)wordDict[i].length());
        }

        int l = s.length();
        vector<bool> dp(l+1,0);
        dp[0] = true;

        for(int i=1;i<=l;++i){
            for(int j=i-1;j>=max(0,i-max_length);j--){
                if(sset.find(s.substr(j,i-j))!=sset.end()){
                    dp[i] = dp[i] || dp[j];
                }
            }
        }
        return dp[l];
    }
};
