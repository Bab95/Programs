class Solution {
public:
    int balancedStringSplit(string s) {
        vector<int> preR(s.length(), 0), preL(s.length(), 0), postR(s.length(), 0), postL(s.length(), 0);
        int r = 0;
        int count = 0;
        for (int i=0;i<s.length();i++){
            r = (s[i]=='R')?(r+1) : (r-1);
            count = (r==0)?(count+1) : count;
        }
        return count;
    }
};