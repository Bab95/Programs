class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<int> position(32, 0);
        for(int i=0;i<32;i++){
            int mask = 1 << i;
            for(int j=0;j<nums.size();j++){
                int x = (nums[j] & mask);
                if (x){
                    position[31-i]++;
                }
            }
        }
        
        int count = 0;
        for (int i=0;i<32;i++){
            count += (position[i] * (nums.size()-position[i]));
        }
        return count;
    }
};