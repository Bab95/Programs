class Solution {
public:
    bool isValid(string s) {
        if(s.length()==0){
            return true;
        }
        stack<char> stk;
        for(int i=0;i<s.length();++i){
            if(s[i]=='('||s[i]=='{'||s[i]=='['){
                stk.push(s[i]);
            }else{
                if(stk.empty()){
                    return false;
                }else{
                    char tt = stk.top();
                    stk.pop();
                    if(s[i]==')'&&tt!='('){
                        return false;
                    }else if(s[i]==']'&&tt!='['){
                        return false;
                    }else if(s[i]=='}'&&tt!='{'){
                        return false;
                    }
                }
            }
        }
        if(stk.empty()){
            return true;
        }
        return false;
    }
};
