class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mmap;
        int sum = 0;
        int max_len = 0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]==0){
                sum+=-1;
            }else if(nums[i]==1){
                sum+=1;
            }
            //cout<<"sum and i"<<i<<" "<<sum<<endl;
            if(sum==0){
                //cout<<"this "<<i<<endl;
                max_len = max(max_len,i+1);
            }else if(mmap.find(sum)!=mmap.end()){
                int current = i-mmap[sum];
                max_len = max(current,max_len);
                //cout<<"maximum: "<<max_len<<" "<<i<<endl;
            }
            if(mmap.find(sum)==mmap.end()){
                mmap[sum] = i;
            }
        }
        /*for(auto it=mmap.begin();it!=mmap.end();++it){
            cout<<it->first<<" "<<it->second<<endl;
        }*/
        return max_len;
    }
};
