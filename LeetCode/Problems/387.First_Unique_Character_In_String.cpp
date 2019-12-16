#define SIZE 26
class Solution {
public:
    int firstUniqChar(string s) {
        int hash[SIZE];
        for(int i=0;i<SIZE;i++){
            hash[i] = 0;
        }
        for(int i=0;i<s.length();i++){
            hash[(int)s[i]-97]++;
        }
        for(int i=0;i<s.length();i++){
            if(hash[(int)s[i]-97]==1){
                return i;
            }
        }
        return -1;
    }
};
