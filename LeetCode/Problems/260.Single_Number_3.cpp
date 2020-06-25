class Solution {
public:
    int getbit(int n,int b){
        while(b-->0){
            n=n>>1;
        }
        return n&1;
    }
    vector<int> singleNumber(vector<int>& nums) {
        int x = nums[0];
        for(int i=1;i<nums.size();++i){
            x^=nums[i];
        }

        //x is xor of these two numbers.........
        //finding the first set bit in x...
        int b = 0;
        int tmp = x;
        while(tmp!=0&&!(tmp&1)){
            tmp = tmp>>1;
            //cout<<tmp<<endl;
            b++;
        }
        //cout<<x<<" :"<<b<<endl;
        int xor_1 = 0;
        int xor_2 = 0;
        for(int i=0;i<nums.size();++i){
            if(getbit(nums[i],b)==1){
                if(xor_1==0){
                    xor_1 = nums[i];
                }else{
                    xor_1 ^= nums[i];
                }
            }else{
                if(xor_2==0){
                    xor_2 = nums[i];
                }else{
                    xor_2^=nums[i];
                }
            }
        }
        return {xor_1,xor_2};
    }
};
