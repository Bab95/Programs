class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        int p = 0;
        int tmp = x;
        while(tmp){
            tmp = tmp/10;
            p++;
        }
        tmp = x;
        while(x&&p>1){
            int first = x/(int)pow(10,p-1);
            int last = x%10;
            if(first!=last){
                return false;
            }
            x = x - first*((int)pow(10,p-1));
            x = x/10;
            p = p-2;
        }
        return true;
    }
};
