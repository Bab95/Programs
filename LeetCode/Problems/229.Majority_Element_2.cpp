class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        pair<int,int> n1,n2;
        n2.first = n1.first = INT_MIN;
        n2.second = n1.second = 0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]==n1.first){
                n1.second++;
            }
            else if(nums[i]==n2.first){
                n2.second++;
            }else if(n1.second==0){
                n1.first = nums[i];
                n1.second = 1;
            }else if(n2.second==0){
                n2.second = 1;
                n2.first = nums[i];
            }else{
                n1.second--;
                n2.second--;
            }
        }
        int c1 = 0;
        int c2 = 0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]==n1.first){
                c1++;
            }else if(nums[i]==n2.first){
                c2++;
            }
        }
        vector<int> ans;
        if(c1>nums.size()/3){
            ans.push_back(n1.first);
        }
        if(c2>nums.size()/3){
            ans.push_back(n2.first);
        }
        return ans;
    }
};
