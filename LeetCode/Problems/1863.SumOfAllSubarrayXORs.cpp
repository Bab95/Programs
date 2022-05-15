class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int total = pow(2, nums.size());
        int sum = 0;
        for (int i = 0;i < total;i++){
            int current = 0;
            for (int j=0;j<nums.size();j++){
                bool x = i & 1<<j;
                if (x){
                    current ^= nums[j];
                }
            }
            sum += current;
            //cout << current << endl;
        }
        return sum;
    }
};