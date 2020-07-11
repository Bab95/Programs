class Solution {
public:
    int myAtoi(string str) {
        int i = 0;
        while(i<str.length()&&str[i]==' '){
            ++i;
        }
        bool sign = true;
        if(i<str.length()){
            if(str[i]=='-'){
                sign = false;
                ++i;
            }else if(str[i]=='+'){
                sign = true;
                ++i;
            }
        }
        long int ans = 0;
        while(i<str.length()&&str[i]>='0'&&str[i]<='9'){
            ans = ans*10 + (long int)(str[i]-'0');
            if(ans>INT_MAX){
                break;
            }
            ++i;
        }
        if(sign==false){
            ans = ans*-1;
        }
        if(ans>INT_MAX){
            return INT_MAX;
        }
        if(ans<INT_MIN){
            return INT_MIN;
        }
        return ans;
    }
};
