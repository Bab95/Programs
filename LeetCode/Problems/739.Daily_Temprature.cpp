class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> ans(n);
        stack<int> s;
        ans[n-1] = 0;
        s.push(n-1);
        for(int i=n-2;i>=0;i--){
            if(T[s.top()]>T[i]){
                ans[i] = s.top()-i;
                s.push(i);
            }else{
                while(!s.empty()&&T[s.top()]<=T[i]){
                    s.pop();
                }
                if(s.empty()){
                    ans[i] = 0;
                }else{
                    ans[i] = s.top()-i;
                }
                s.push(i);
            }
        }
        return ans;
    }
};
