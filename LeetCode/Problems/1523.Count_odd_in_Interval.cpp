class Solution {
public:
    int countOdds(int low, int high) {
        if(low%2==0){
            low++;
        }
        if(high%2==0){
            high--;
        }
        int nums = (high-low);
        nums /= 2;
        nums += 1;
        return nums;
    }
};
