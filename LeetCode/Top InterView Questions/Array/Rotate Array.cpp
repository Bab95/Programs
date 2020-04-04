class Solution {
public:
    inline void swap(int *a,int *b){
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
    void rotate(vector<int>& nums, int k) {
        int l = 0;
        int r = nums.size()-1;
        int n = nums.size();
        k = k%n;
        while(l<r){
            swap(&nums[l],&nums[r]);
            l++;
            r--;
        }
        l = 0;
        r = k-1;
        while(l<r){
            swap(&nums[l],&nums[r]);
            l++;r--;
        }
        l = k;
        r = nums.size()-1;
        while(l<r){
            swap(&nums[l],&nums[r]);
            l++;
            r--;
        }
    }
};