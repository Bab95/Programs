class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/"){
                int op2 = stk.top();//atoi(stk.top());
                stk.pop();
                int op1 = stk.top();//atoi(stk.top());
                stk.pop();
                int result = 0;
                /*switch(tokens[i]){
                    case "+":
                        result = op1+op2;
                        break;
                    case "-":
                        result = op1-op2;
                        break;
                    case "/":
                        result = op1/op2;
                        break;
                    case "*":
                        result = op1*op2;
                        break;

                }*/
                if(tokens[i]=="+"){
                    result = op1+op2;
                }else if(tokens[i]=="-"){
                    result = op1-op2;
                }else if(tokens[i]=="*"){
                    result = op1*op2;
                }else{
                    result = op1/op2;
                }
                stk.push(result);
            }else{
                int tmp = stoi(tokens[i]);
                stk.push(tmp);
            }

        }
        return stk.top();
    }
};
