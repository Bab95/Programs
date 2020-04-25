class Solution {
public:
    bool isopening(char c){
        if(c=='('||c=='{'||c=='['){
            return true;
        }
        return false;
    }
    bool isSameKind(char a,char b){
        if(a==')'&&b=='('){
            return  true;
        }
        if(a==']'&&b=='['){
            return true;
        }
        if(b=='{'&&a=='}'){
            return true;
        }
        return false;
    }
    bool isValid(string s) {
        stack<char> stk;
        for(char c : s){
            if(isopening(c)){
                stk.push(c);
            }else{
                if(stk.empty()){
                    cout<<"this";
                    return false;
                }
                char d = stk.top();
                stk.pop();
                if(!isSameKind(c,d)){
                    return false;
                }
            }
        }
        if(!stk.empty()){
            return false;
        }
        return true;
    }
};
