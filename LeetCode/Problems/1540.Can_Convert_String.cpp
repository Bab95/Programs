class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if(s.length()!=t.length()){
            return false;
        }
        vector<int> multiple(26,0);
        for(int i=0;i<s.length();++i){
            if(s[i]==t[i]){
                continue;
            }else{
                int moves = (int)(t[i]-s[i]);
                if(moves<0){
                    moves += 26;
                }
                if(moves>k){
                    return false;
                }
                if(multiple[moves]==0){
                    multiple[moves] = moves + 26;
                }else{
                    moves = multiple[moves];
                    if(moves>k){
                        return false;
                    }else{
                        multiple[moves%26] += 26;
                    }
                }
            }
        }
        return true;
    }
};
