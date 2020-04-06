class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<char,int> mmap;
        for(int i=0;i<J.length();i++){
            mmap[J[i]] = 1;
        }
        int count = 0;
        for(int i=0;i<S.length();i++){
            if(mmap.count(S[i])!=0){
                count++;
            }
        }
        return count;
    }
};
