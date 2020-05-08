class Solution {
public:
    int myAtoi(string str) {
        int i = 0;
        while(i<str.length()&&str[i]==' '){
            ++i;
        }
        if(i>=str.length()){
            return 0;
        }
        int sign = 1;
        if(str[i]=='-'){
            sign = -1;
            i++;
        }
        else if(str[i]=='+'){
            ++i;
        }
        long long int ans = 0;
        while(i<str.length()&&str[i]>='0'&&str[i]<='9'){
            ans = ans*10+(str[i]-'0');
            if(sign*ans>INT_MAX){
                return INT_MAX;
            }else if(sign*ans<INT_MIN){
                return INT_MIN;
            }
            i++;
        }
        return (int)(ans*sign);
    }
};
