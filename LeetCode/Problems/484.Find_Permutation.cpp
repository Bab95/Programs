class Solution {
public:
    vector<int> findPermutation(string s) {
        vector<int> result(s.length()+1);
        for(int i=0;i<=s.length();++i){
            result[i] = i+1;
        }
        int i=1;
        while(i<=s.length()){
            int j = i;
            while(i<=s.length()&&s[i-1]=='D'){
                i++;
            }
            int l = j-1;
            int r = i-1;
            while(l<r){
                swap(result[l],result[r]);
                ++l;
                --r;
            }
            ++i;
        }
        return result;
    }
};
