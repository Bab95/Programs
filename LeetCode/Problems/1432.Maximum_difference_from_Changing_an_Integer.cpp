class Solution {
public:
    int number(vector<int>& arr){
        int result = 0;
        for(int i=0;i<arr.size();++i){
            result = result*10+arr[i];
        }
        return result;
    }
    int maxDiff(int num) {
        vector<int> arr;
        int n = num;
        while(n){
            int rem = n%10;
            n = n/10;
            arr.push_back(rem);
        }
        int l = 0;
        int r = arr.size()-1;
        while(l<r){
            swap(arr[l],arr[r]);
            l++;
            r--;
        }
        vector<int> nums;
        vector<int> changenum;
        /*for(int i=0;i<arr.size();++i){
            cout<<arr[i];
        }*/
        for(int i=9;i>=0;i--){
            for(int j=0;j<=9;j++){
                changenum.insert(changenum.begin(),arr.begin(),arr.end());
                //x = i y = j......
                for(int k=0;k<changenum.size();k++){
                    if(changenum[k]==i){
                        changenum[k] = j;
                    }
                }
                if(changenum[0]!=0){
                    nums.push_back(number(changenum));
                }
                changenum.clear();
                /*for(int p=0;p<changenum.size();p++){
                    cout<<changenum[p];
                }*/
            }

        }

        sort(nums.begin(),nums.end());
        /*for(int i=0;i<nums.size();++i){
            cout<<nums[i]<<endl;
        }*/
        return nums[nums.size()-1]-nums[0];
    }
};
