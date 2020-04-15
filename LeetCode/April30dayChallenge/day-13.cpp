class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int max_length = 0;
        int start = 0;
        int max_start = -1;
        int sum = 0;
        unordered_map<int,int> mmap; 
        for(int i=0;i<nums.size();++i){
            if(nums[i]==0){
                sum+=(-1);
            }else{
                sum+=1;
            }
            if(sum==0){
                max_length = max(max_length,i+1);
            }
            if(mmap.find(sum)!=mmap.end()){
                int current = i - mmap[sum];
                if(current>max_length){
                    max_length = current;
                    max_start = mmap[sum];
                }
            }else{
                mmap[sum] = i;
            }
        }
        /*if(mmap.find(sum)!=mmap.end()){
            int current = nums.size() - mmap[sum] + 1;
            max_length = max(max_length,current);
        }*/
        return max_length;
    }
};