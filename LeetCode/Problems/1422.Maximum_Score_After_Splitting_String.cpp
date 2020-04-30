class Solution {
public:
    int maxScore(string s) {
        vector<int> zeros(s.length(),0);
        vector<int> ones(s.length(),0);
        if(s[0]=='0'){
            zeros[0] = 1;
        }else{
            ones[0] = 1;
        }
        for(int i=1;i<s.length();++i){
            if(s[i]=='0'){
                zeros[i] = zeros[i-1]+1;
                ones[i] = ones[i-1];
            }else{
                ones[i] = ones[i-1]+1;
                zeros[i] = zeros[i-1];
            }
        }

        int max_score = 0;
        for(int i=0;i<s.length()-1;++i){
            int current_score = zeros[i] + ones[s.length()-1]-ones[i];
            max_score = max(max_score,current_score);
        }
        return max_score;
    }
};
