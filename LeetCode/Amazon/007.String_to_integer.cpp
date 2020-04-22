class Solution {
public:
    int myAtoi(string str) {
        int sign = 1;
        //removing white spaces...
        int i = 0;
        while(str[i]==' ')
            ++i;

        if(str[i]=='-'){
            sign = -1;
            ++i;
        }else if(str[i]=='+'){
            ++i;
        }else if(str[i]>58||str[i]<48){
            //not possible
            return 0;
        }
        long long int ans = 0;
        while(i<str.length()&&str[i]-'0'>=0&&str[i]-'0'<=9){
            ans = ans*10+(str[i]-'0');
            if(ans*sign>INT_MAX){
                return INT_MAX;
            }
            if(ans*sign<INT_MIN){
                return INT_MIN;
            }
            ++i;
        }
        ans = sign*ans;
        /*if(ans>INT_MAX){
            return INT_MAX;
        }
        if(ans<INT_MIN){
            return INT_MIN;
        }*/
        return (int)ans;
    }
};
