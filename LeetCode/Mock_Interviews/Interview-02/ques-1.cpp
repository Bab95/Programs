class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> tru_pos;
        tru_pos.insert(tru_pos.begin(),heights.begin(),heights.end());
        sort(tru_pos.begin(),tru_pos.end());
        int ans = 0;
        int i = 0;
        while(i<heights.size()){
            if(tru_pos[i]!=heights[i]){
                ans++;
            }
            ++i;
        }
        return ans;
    }
};
