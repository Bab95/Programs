class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<char,int> J_map;
        for(int i=0;i<J.length();++i){
            J_map[J[i]] = 1;
        }
        int res = 0;
        for(int i=0;i<S.length();++i){
            if(J_map.find(S[i])!=J_map.end()){
                ++res;
            }
        }
        return res;
    }
};
