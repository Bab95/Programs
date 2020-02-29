class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> carries(digits.size(),0);
        int n = digits.size()-1;
        int carry = 1;
        for(int i=digits.size()-1;i>=0;i--){
            digits[i] = digits[i]+carry;
            carry = digits[i]/10;
            digits[i] = digits[i]%10;
            //digit[i-1] += carry;
        }
        if(carry){
            vector<int> result(digits.size()+1);
            result[0] = carry;
            for(int i=0;i<digits.size();i++){
                result[i+1] = digits[i];
            }
            return result;
        }
        return digits;

    }
};
