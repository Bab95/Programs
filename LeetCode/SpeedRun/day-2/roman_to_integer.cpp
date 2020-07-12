class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mmap;
        mmap['I'] = 1;
        mmap['V'] = 5;
        mmap['X'] = 10;
        mmap['L'] = 50;
        mmap['C'] = 100;
        mmap['D'] = 500;
        mmap['M'] = 1000;
        int ans = 0;
        ans = mmap[s[0]];
        for(int i=1;i<s.length();++i){
            if(mmap[s[i]]>mmap[s[i-1]]){
                ans += mmap[s[i]];
                ans -= (2*mmap[s[i-1]]);
            }else{
                ans += mmap[s[i]];
            }
        }
        return ans;
    }
};
