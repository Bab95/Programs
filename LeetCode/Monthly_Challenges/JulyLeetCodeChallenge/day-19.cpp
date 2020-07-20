class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length()-1;
        int j = b.length()-1;
        int carry = 0;
        string ans;
        while(i>=0||j>=0){
            int x,y;
            x = (i>=0)?(a[i]-'0'):0;
            y = (j>=0)?(b[j]-'0'):0;
            int sum = carry +  x + y;
            carry = sum/2;
            sum = sum%2;
            ans.push_back(sum+'0');
            i--;
            j--;
        }
        if(carry!=0){
            ans.push_back('1');
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
