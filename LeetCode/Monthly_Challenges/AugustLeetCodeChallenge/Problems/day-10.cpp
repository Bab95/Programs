class Solution {
public:
    int titleToNumber(string s) {
        unordered_map<char,int> mmap;
        int i;
        for(char c='A',i=1;c<='Z';++c,++i){
            mmap[c] = i;
        }
        i = s.length()-1;
        int ans = 0;
        int p = 0;
        while(i>=0){
            ans += pow(26,p)*mmap[s[i]];
            i--;
            p++;
        }
        return ans;
    }
};
