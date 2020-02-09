class Solution {
public:
    void swap(int& a,int& b){
        int tmp = a;
        a = b;
        b = tmp;
        return;
    }
    int partition(vector<int>& nums,int start,int end){
        int pivot = nums[start];
        int i = start+1;
        for(int j=start+1;j<=end;j++){
            if(nums[j]<pivot){
                swap(nums[i],nums[j]);
                i++;
            }
        }
        swap(nums[start],nums[i-1]);
        return i-1;
    }
    void quicksort(vector<int>& nums,int start,int end){
        if(start<end){
            int pivot = partition(nums,start,end);
            quicksort(nums,start,pivot-1);
            quicksort(nums,pivot+1,end);
        }
    }
    void nextPermutation(vector<int>& nums) {
        if(nums.size()==1||nums.size()==0){
            return;
        }
        if(nums.size()==2){
            swap(nums[0],nums[1]);
            return;
        }
        int n = nums.size()-1;
        int i = n-1;
        while(i>=0&&nums[i]>=nums[i+1]){
            i--;
        }
        if(i<0){
            quicksort(nums,0,n);
        }else{
            int index = i+1;
            int num = nums[i];
            for(int j=i+2;j<=n;j++){
                if(nums[j]>nums[i]&&nums[j]<nums[index]){
                    index = j;
                }
            }
            swap(nums[i],nums[index]);
            quicksort(nums,i+1,n);
        }

    }
};
