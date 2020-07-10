class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int i = digits.size()-1;
        while(i>=0){
            digits[i] += carry;
            carry = digits[i]/10;
            digits[i] %= 10;
            i--;
            if(carry==0){
                return digits;
            }
        }
        if(carry==1){
            vector<int> ans;
            ans.push_back(1);
            ans.insert(ans.end(),digits.begin(),digits.end());
            return ans;
        }
        return digits;
    }
};
