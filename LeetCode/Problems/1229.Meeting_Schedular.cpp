class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        vector<vector<int> > s1,s2;
        for(int i=0;i<slots1.size();++i){
            if(slots1[i][1]-slots1[i][0]>=duration){
                s1.push_back(slots1[i]);
            }
        }

        for(int i=0;i<slots2.size();++i){
            if(slots2[i][1]-slots2[i][0]>=duration){
                s2.push_back(slots2[i]);
            }
        }
        sort(s1.begin(),s1.end(),[](const auto& v1,const auto& v2){
            return v1[0]<v2[0];
        });

        sort(s2.begin(),s2.end(),[](const auto& v1,const auto& v2){
            return v1[0]<v2[0];
        });

        int i = 0;
        int j = 0;
        while(i<s1.size()&&j<s2.size()){
            int a_start = s1[i][0];
            int a_end = s1[i][1];
            int b_start = s2[j][0];
            int b_end = s2[j][1];
            if(b_start>=a_end||(b_start>=a_start&&(a_end-b_start<duration))){
                ++i;
            }else if(a_start>=b_end||(a_start>=b_start&&(b_end-a_start<duration))){
                j++;
            }else{
                vector<int> ans(2,0);
                ans[0] = max(a_start,b_start);
                ans[1] = ans[0] + duration;
                return ans;
            }
        }
        return {};
    }
};
