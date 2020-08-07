class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int> > ans;
        for(int i=0;i<S.length();){
            char current = S[i];
            int start = i;
            while(i<S.length()&&S[i]==current){
                i++;
            }
            if(i-start>=3){
                ans.push_back({start,i-1});
            }
        }
        return ans;
    }
};
