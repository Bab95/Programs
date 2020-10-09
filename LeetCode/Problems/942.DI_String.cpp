class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> ans(S.length()+1);
        for(int i=0;i<=S.length();++i){
            ans[i] = i;
        }
        for(int i=1;i<=S.length();++i){
            if(S[i-1]=='D'){
                int start = i-1;
                int j = start+1;
                while(j<S.length()&&S[j]=='D'){
                    j++;
                }
                i = j+1;
                while(start<j){
                    swap(ans[start],ans[j]);
                    start++;
                    j--;
                }
            }
        }
        return ans;
    }
};


/*
IDID
02143
*/
