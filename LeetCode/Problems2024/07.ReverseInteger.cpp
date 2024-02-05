class Solution {
public:
    int reverse(int x) {
        int result = 0;
        int flag = 1;
        if (x == INT_MIN || x == INT_MAX) {
            return 0;
        }
        if (x < 0) {
            flag = -1;
            x = -1 * x;
        }
        int max_int = INT_MAX;
        while (x > 0) {
            int a = x % 10;
            x = x / 10;
            if (max_int / 10 < result){
                return 0;
            }
            int temp = result * 10 + a;
            result = temp;
        }
        if (flag == -1) {
            result = result * -1;
        }
        return result;
    }
};
