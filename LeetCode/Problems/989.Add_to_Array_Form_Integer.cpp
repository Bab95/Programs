class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {

        vector<int> ans;
        int i = A.size()-1;
        int carry = 0;
        while(i>=0 || K>0){
            int last_digit = K%10;
            K /= 10;
            int digit = ((i>=0)?A[i]:0);
            digit = digit + last_digit + carry;
            carry = digit/10;
            digit = digit%10;
            ans.push_back(digit);
            i--;
        }
        if(carry!=0){
            ans.push_back(carry);
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};
