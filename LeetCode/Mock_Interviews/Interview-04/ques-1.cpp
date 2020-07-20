class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        if(bits.size()==1){
            return true;
        }
        vector<bool> dp(bits.size(),false);
        if(bits[0]==0){
            dp[0] = true;
        }else{
            dp[0] = false;
        }
        for(int i=1;i<bits.size()-1;++i){
            if(bits[i]==0){
                dp[i] = true;
                if(bits[i-1]==1&&!dp[i-1]){
                    dp[i-1] = true;
                }

            }
            else if(bits[i]==1){
                if(bits[i-1]==1){
                    if(dp[i-1]==false){
                        dp[i] = true;
                        dp[i-1] = true;
                    }else{
                        dp[i] = false;
                    }
                }else if(bits[i-1]==0){
                    dp[i] = false;
                }
            }

        }
        bool ans = true;
        for(int i=0;i<dp.size()-1;++i){
            ans = ans&dp[i];
        }
        return ans;

    }
};
