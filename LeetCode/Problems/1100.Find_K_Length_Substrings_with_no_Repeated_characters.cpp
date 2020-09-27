class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        if(k>s.length()||k>26){
            return 0;
        }
        vector<int> last(26,-1);
        int ans = 0;
        int len = 0;
        for(int i=0;i<s.length();++i){
            int j = s[i]-'a';
            if(last[j]==-1||i-min(k,len)>last[j]){
                len++;
                if(len>=k){
                    ans++;
                }
            }else{
                len = min(i-last[j],k);
                if(len>=k){
                    ans++;
                }
            }
            last[j] = i;
        }
        return ans;
    }
};
/*
"havefunonleetcode"
5
"bbbbabbaba"
2
"gdggdbjchgadcfddfahbdebjbagaicgeahehjhdfghadbcbbfhgefcihbcbjjibjdhfhbdijehhiabad"
5
*/
