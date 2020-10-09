class Solution {
public:
    string customSortString(string S, string T) {
        vector<int> hash(26,INT_MAX);
        for(int i=0;i<S.length();++i){
            hash[S[i]-'a'] = i;
        }
        sort(T.begin(),T.end(),[&](auto const& a,auto const& b){
            return hash[a-'a']<hash[b-'a'];
        });
        return T;
    }
};
