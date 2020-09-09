class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stk;
        for(int i=0;i<s.length();++i){
            if(stk.empty()){
                stk.push(s[i]);
            }else{
                if(stk.top()==s[i]){
                    while(!stk.empty()&&stk.top()==s[i]){
                        stk.pop();
                    }
                }else{
                    stk.push(s[i]);
                }
            }
        }
        string ans;
        while(!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
