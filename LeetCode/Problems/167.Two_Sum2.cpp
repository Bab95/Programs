class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size()-1;
        vector<int> result;
        while(l<r){
            if(numbers[l]+numbers[r]==target){
                result.push_back(l+1);
                result.push_back(r+1);
                l++;
                r--;
            }else if(numbers[l]+numbers[r]>target){
                r--;
            }else{
                l++;
            }
        }
        return result;
    }
};
