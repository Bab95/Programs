class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        set<int> ss;
        int ans = 0;
        for(int i=0;i<light.size();++i){
            ss.insert(light[i]);
            int m = *ss.rbegin();
            if(m==ss.size()){
                ans++;
            }
        }
        return ans;
    }
};
