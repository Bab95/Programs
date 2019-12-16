class Solution {
public:
 vector<vector<int> > threeSum(vector<int>& nums) {
	sort(nums.begin(),nums.end());
	int n = 0;
	n = nums.size();
	int l,r;
	vector<vector<int> > result;
	for(int i=0;i<n-1;){
		l = i+1;
		r = n-1;
		while(l<r){
			if(nums[l]+nums[r]+nums[i]==0){
				vector<int> mini_res;
				mini_res.push_back(nums[l]);
				mini_res.push_back(nums[i]);
				mini_res.push_back(nums[r]);
				result.push_back(mini_res);
				//cout<<nums[i]<<" "<<nums[l]<<" "<<nums[r]<<endl;
				//l++;r--;
				while(l<n-1&&nums[l]==nums[l+1]){
					l++;
				}
				l++;
				while(r>l&&nums[r]==nums[r-1]){
					r--;
				}
				r--;
			}else if(nums[l]+nums[r]+nums[i]>0){
				while(r>l&&nums[r]==nums[r-1]){
					r--;
				}
				r--;
			}else{
				while(l<n-1&&nums[l]==nums[l+1]){
					l++;
				}
				l++;
			}
		}
		while(i<n-1&&nums[i]==nums[i+1]){
			i++;
		}
		i++;
	}
    return result;
}


};
