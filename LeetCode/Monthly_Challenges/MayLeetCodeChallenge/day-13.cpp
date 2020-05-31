class Solution {
public:
    string removeKdigits(string num, int k) {
        cout<<num.length()<<endl;
        stack<char> stk;
        for(int i=0;i<num.length();++i){
            while(k>0&&!stk.empty()&&(int)num[i]<(int)stk.top()){
                k--;
                stk.pop();
            }
            stk.push(num[i]);
        }
        while(k){
            k--;
            stk.pop();
        }
        int n = stk.size();
        for(int i=n-1;i>=0;i--){
            num[i] = stk.top();
            stk.pop();
        }
        int i = 0;
        //cout<<num.substr(0,n)<<endl;
        while(n>0&&num[i]=='0'){
            i++;
            n--;
        }
        if(n==0){
            return "0";
        }
        return num.substr(i,n);
    }
};
