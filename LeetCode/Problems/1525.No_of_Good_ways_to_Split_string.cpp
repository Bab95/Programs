class Solution {
public:
    int numSplits(string s) {
        unordered_map<char,int> forward,backward;
        for(auto c : s){
            backward[c] += 1;
        }
        int ans = 0;
        for(int i=0;i<s.size();++i){
            backward[s[i]]-=1;
            forward[s[i]]+=1;
            if(backward[s[i]]==0){
                backward.erase(s[i]);
            }
            if(forward.size()==backward.size()){
                ans+=1;
            }
        }
        return ans;
    }
};
