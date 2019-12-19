#include <limits.h>
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
    bool valid(vector<int> &a){
        if(a[0]==INT_MAX){
            return false;
        }
        return true;
    }
    bool issame(vector<vector<int> > &result,int l,int j){
        if(result[l][0]==result[j][0]&&result[l][1]==result[j][1]&&result[l][2]==result[j][2]&&result[l][3]==result[j][3]){
            return true;
        }
        return false;
    }
    void change(vector<vector<int> > &result,int j){
        result[j][0] = INT_MAX;
        result[j][1] = INT_MAX;
        result[j][2] = INT_MAX;
        result[j][3] = INT_MAX;
        return;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        quicksort(nums,0,n-1);
        vector<vector<int> > result;
        for(int i=0;i<=n-4;i++){
            for(int j=i+1;j<=n-3;j++){
                int k = j+1;
                int m = n-1;
                while(k<m){
                    if(nums[i]+nums[j]+nums[k]+nums[m]==target){
                        vector<int> tmp(4);
                        tmp[0] = nums[i];
                        tmp[1] = nums[j];
                        tmp[2] = nums[k];
                        tmp[3] = nums[m];
                        result.push_back(tmp);
                        k++;
                        m--;
                    }else if(nums[i]+nums[j]+nums[k]+nums[m]>target){
                        m--;
                    }else{
                        k++;
                    }
                }
            }
        }
        vector<vector<int> > unique_res;
        vector<vector<int> >::iterator itr,jtr;
        /*for(itr=result.begin();itr!=result.end();itr++){
            for(jtr=itr+1;jtr!=result.end();jtr++){

            }
        }*/
        for(int i=0;i<result.size();i++){
            if(valid(result[i])){
                unique_res.push_back(result[i]);
            }else{
                continue;
            }
            for(int j=i+1;j<result.size();j++){
                if(issame(result,i,j)){
                    change(result,j);
                }
            }
        }

        return unique_res;
        //return result;

    }
};
