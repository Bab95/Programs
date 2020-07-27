class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        if(s.length()==0){
            return s;
        }
        string ans(s.length(),'0');
        for(int i=0;i<indices.size();++i){
            ans[indices[i]] = s[i];
        }
        return ans;
    }
};
