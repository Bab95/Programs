class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int res = 0;
        int temp = x;
        int int_max = INT_MAX;
        while (temp) {
            if (int_max / 10 < res)
                return false; 
            res = res * 10 + temp%10;
            temp = temp / 10;
        }
        return res == x;
    }
};
