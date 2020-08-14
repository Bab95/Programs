class Solution {
public:
    string reverseStr(string s, int k) {
        if(k==1){
            return s;
        }
        int start = 0;
        while(start<s.length()){
            int i = start;
            int j = min(start+k-1,(int)s.length()-1);
            while(i<j){
                swap(s[i],s[j]);
                ++i;
                --j;
            }
            start = start + 2*k;
        }
        return s;
    }
};
