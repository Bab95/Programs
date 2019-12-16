#define RANGEUP 2147483647
#define RANGEDOWN -2147483648
class Solution {
public:
    int myAtoi(string str) {
        int multiplier = 1;
        int start = 0;
        while(str[start]==' '){
            start++;
        }
        /*if(str[start]<48||str[start]>57){
            if(str[start]!='-'){
                return 0;
            }else if(str[start]!='+'){
                return 0;
            }
        }*/
        if(str[start]=='-'){
            multiplier = -1;
            start++;
        }else if(str[start]=='+'){
            start++;
        }else if(str[start]<48||str[start]>57){
            return 0;
        }
        long long ans = 0;
        for(int i=start;i<str.length();i++){
            if(str[i]<48||str[i]>57){
                break;
            }
            int val = (int)str[i]-48;
            ans = ans*10+val;
            if(ans*multiplier>=RANGEUP){
                return RANGEUP;
            }
            if(ans*multiplier<=RANGEDOWN){
                return RANGEDOWN;
            }
        }
        ans = ans*multiplier;
        if(ans>RANGEUP||ans<RANGEDOWN){
            return RANGEDOWN;
        }
        return ans;
    }
};
