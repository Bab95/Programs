#include <stack>
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='['){
                stk.push(s[i]);
            }else if(s[i]==')'){
                if(stk.empty()){
                    return false;
                }else{
                    char tmp = stk.top();
                    stk.pop();
                    if(tmp!='('){
                        return false;
                    }
                }
            }else if(s[i]=='}'){
                if(stk.empty()){
                    return false;
                }else{
                    char tmp = stk.top();
                    stk.pop();
                    if(tmp!='{'){
                        return false;
                    }
                }
            }else if(s[i]==']'){
                if(stk.empty()){
                    return false;
                }else{
                    char tmp = stk.top();
                    stk.pop();
                    if(tmp!='['){
                        return false;
                    }

                }
            }
        }
        if(!stk.empty()){
            return false;
        }
        return true;
    }
};
