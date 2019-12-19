#define INT_MAX 100001
class Solution {
public:
    void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
    }
    int partition(vector<int> &A,int start,int end){
        int i = start+1;
        int pivot = A[start];
        for(int j=start+1;j<=end;j++){
            if(A[j]<pivot){
                swap(&A[i],&A[j]);
                i++;
            }
        }
        swap(&A[start],&A[i-1]);
        return i-1;
    }
    void quicksort(vector<int> &A,int start,int end){
        if(start<end){
            int pivot = partition(A,start,end);
            quicksort(A,start,pivot-1);
            quicksort(A,pivot+1,end);
        }
    }
    int mod(int x){
        if(x<0){
            x = x*-1;
            return x;
        }
        return x;
    }
    int threeSumClosest(vector<int>& nums, int target) {
        quicksort(nums,0,nums.size()-1);
        int mindiff = INT_MAX;
        int result = INT_MIN;
        int n = nums.size();
        for(int i=n-1;i>=2;i--){
            int l = 0,r=i-1;
            while(l<r){
                if(nums[l]+nums[r]+nums[i]==target){
                    return target;
                }else if(nums[l]+nums[r]+nums[i]>target){
                    int tmp = target-(nums[l]+nums[r]+nums[i]);
                    tmp = mod(tmp);
                    if(mindiff>tmp){
                        result = nums[l]+nums[r]+nums[i];
                        mindiff = tmp;
                    }
                    r--;
                }else{
                    int tmp = target-(nums[l]+nums[r]+nums[i]);
                    tmp = mod(tmp);
                    if(mindiff>tmp){
                        result = nums[l]+nums[r]+nums[i];
                        mindiff = tmp;
                    }

                    l++;
                }
            }
        }
        return result;
    }
};
