class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.length()-1;
        int n = b.length()-1;
        string result;
        int i = 0;
        int carry = 0;
        while(m>=0&&n>=0){
            int x = (m>=0)?(a[m]-'0'):0;
            int y = (n>=0)?(b[n]-'0'):0;
            int tmp = x + y + carry;
            result.push_back(tmp%2+'0');
            carry = tmp/2;
            m--;
            n--;
        }
        while(m>=0){
            int tmp = carry+(a[m]-'0');
            result.push_back(tmp%2+'0');
            carry = tmp/2;
            m--;
        }
        while(n>=0){
            int tmp = carry+(b[n]-'0');
            result.push_back(tmp%2+'0');
            carry = tmp/2;
            n--;
        }
        if(carry!=0){
            result.push_back(carry+'0');
        }
        int l = 0;
        int r = result.size()-1;
        while(l<r){
            char tmp = result[l];
            result[l] = result[r];
            result[r] = tmp;
            ++l;
            --r;
        }
        return result;

    }
};
