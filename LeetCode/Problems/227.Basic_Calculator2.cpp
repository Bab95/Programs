class Solution {
public:
    int precedence(string& a){
        if(a=="+"||a=="-"){
            return 1;
        }else if(a=="*"||a=="/"){
            return 2;
        }else if(a=="^"){
            return 3;
        }
        return 0;
    }
    bool operand(string& s){
        if(s[0]>='0'&&s[0]<='9'){
            return true;
        }
        return false;
    }
    vector<string> topostfix(vector<string>& postfix){
        vector<string> ans;
        stack<string> stk;
        for(int i=0;i<postfix.size();++i){
            if(operand(postfix[i])){
                cout<<postfix[i]<<endl;
                ans.push_back(postfix[i]);
            }else{
                cout<<"vlksjablkvc"<<endl;
                if(stk.empty()){
                    stk.push(postfix[i]);
                }else if(precedence(stk.top())<precedence(postfix[i])){
                    stk.push(postfix[i]);
                }else{
                    while(!stk.empty()&&precedence(postfix[i])<precedence(stk.top())){
                        ans.push_back(stk.top());
                        stk.pop();
                    }
                    stk.push(postfix[i]);
                }
            }
        }
        while(!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }
        for(string s:ans){
            cout<<s<<endl;
        }
        cout<<"----------------"<<endl;
        return ans;
    }
    int operate(string& op,int op1,int op2){
        if(op=="+"){
            return op1+op2;
        }
        if(op=="*"){
            return op1*op2;
        }
        if(op=="/"){
            return op1/op2;
        }
        if(op=="-"){
            return op1-op2;
        }
        return 1;
    }
    int evaluate(vector<string>& postfix){
        stack<int> stk;
        for(string it:postfix){
            if(operand(it)){
                stk.push(stoi(it));
            }else{
                int op1 = stk.top();
                stk.pop();
                int op2 = stk.top();
                stk.pop();
                int ans = operate(it,op1,op2);
                stk.push(ans);
            }
        }
        return stk.top();
    }
    int calculate(string s) {
        vector<string> postfix;
        string current;
        for(int i=0;i<s.length();++i){
            if(s[i]>='0'&&s[i]<='9'){
                current.push_back(s[i]);
            }else{
                postfix.push_back(current);
                current.clear();
                postfix.push_back(to_string(s[i]));
            }
        }
        postfix.push_back(current);
        postfix = topostfix(postfix);
        for(string s:postfix){
            cout<<s<<endl;
        }
        return evaluate(postfix);
    }
};