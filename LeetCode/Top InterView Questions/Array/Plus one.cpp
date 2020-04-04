class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int i = digits.size()-1;
        while(i>=0&&carry){
            int sum = digits[i]+carry;
            carry = sum/10;
            digits[i] = sum%10;
            i--;
        }
        if(carry){
            digits.insert(digits.begin(),1,carry);
        }
        return digits;
    }
};