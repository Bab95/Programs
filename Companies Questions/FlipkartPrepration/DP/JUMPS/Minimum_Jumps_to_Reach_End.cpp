/*
TC=>O(N)
SC=>O(1)
keep the track of max_reach at any point
We assuming that we can always reach the end
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()<=1){
            return 0;
        }
        if(nums[0]==0){
            return -1;
        }
        int max_reach = nums[0];
        int steps = nums[0];
        int jumps = 1;
        int n = nums.size();
        for(int i=1;i<n;++i){
            if(steps<i){
                jumps++;
                steps = max_reach;
            }
            max_reach = max(max_reach,i+nums[i]);
        }
        return jumps;
    }
};

/*HANDLES THE CASES WHEN WE CAN'T REACH*/
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()<=1){
            return 0;
            
        }   
        if(nums[0]==0){
            return -1;
        }
        int n = nums.size();
        int steps = nums[0];
        int max_reach = nums[0];
        int jumps = 1;
        for(int i=1;i<nums.size();++i){
            if(i==n-1){
                return jumps;
            }
            max_reach = max(max_reach,i+nums[i]);
            steps--;
            if(steps==0){
                jumps++;
                if(i>=max_reach){
                    return -1;
                }   
                steps = max_reach-i;
            }
            
        }
        return jumps+1;
        
    }
};