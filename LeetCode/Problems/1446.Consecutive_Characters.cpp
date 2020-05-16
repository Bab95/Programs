class Solution {
public:
    int maxPower(string s) {
        int ans = 0;
        for(int i=0;i<s.length();){
            char now = s[i];
            int tmp = 0;
            while(i<s.length()&&s[i]==now){
                tmp++;
                i++;
            }
            //cout<<now<<" :"<<tmp<<endl;
            if(tmp>ans){
                ans = tmp;
            }
        }
        return ans;
    }
};
