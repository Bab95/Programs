class Solution {
public:
    int longestPalindrome(string s) {
        if(s.length()==0){
            return 0;
        }
        unordered_map<char,int> mmap;
        for(auto &c : s){
            mmap[c] += 1;
        }
        int odds = 0;
        int ans = 0;
        for(auto it=mmap.begin();it!=mmap.end();++it){
            ans += it->second;
            if(it->second%2==1){
                odds++;
            }
        }
        if(odds!=0){
            ans -= (odds-1);
        }
        return ans;
    }
};
