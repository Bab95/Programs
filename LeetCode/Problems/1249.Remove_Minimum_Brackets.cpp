class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> stk;
        int open = 0;
        for(int i=0;i<s.length();++i){
            if(s[i]=='('){
                open++;
                stk.push(s[i]);
            }else if(s[i]==')'){
                if(open>0){
                    open--;
                    stk.push(s[i]);
                }
            }else{
                stk.push(s[i]);
            }
        }
        if(stk.size()==0){
            return "";
        }
        string ans;
        ans.reserve(stk.size());
        while(!stk.empty()){
            char current = stk.top();
            stk.pop();
            if(current=='('){
                if(open>0){
                    open--;
                    //ans.push_back(current);
                }else{
                    ans.push_back(current);
                }
            }else{
                ans.push_back(current);
            }
        }
        int i = 0;
        int j = ans.length()-1;
        while(i<j){
            char tmp = ans[i];
            ans[i] = ans[j];
            ans[j] = tmp;
            ++i;
            --j;
        }
        return ans;

    }
};
