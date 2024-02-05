class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() <= 1) {
            return s.length();
        }
        unordered_map<char, int> mmap;
        int max_length = -1;
        int current_length = 0;
        for (int i=0;i<s.length();i++) {
            if (mmap.find(s[i]) == mmap.end()) {
                current_length++;
            } else {
                if (i - current_length > mmap[s[i]]) {
                    current_length++;
                }else{
                    current_length = i - mmap[s[i]];
                }
            }
            mmap[s[i]] = i;
            max_length = max(max_length, current_length);
        }
        return max_length;
    }
};
