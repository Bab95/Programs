#include <algorithm>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		int n = nums.size();
		vector<pair<int,int> > vec;
		//pair<int,int> p;
		for(int i=0;i<n;i++){
			vec.push_back(make_pair(nums[i],i));
		}
		sort(vec.begin(),vec.end());
		int l = 0,r = n-1;
		/*cout<<"sorted vector"<<endl;
		for(vector<pair<int,int> >::iterator itr=vec.begin();itr!=vec.end();itr++){
			cout<<itr->first<<" "<<itr->second<<endl;
		}*/
		vector<int> result;
		while(l<r){
			if(vec[l].first+vec[r].first==target){
				result.push_back(vec[l].second);
				result.push_back(vec[r].second);
				l++;r--;
				break;
			}else if(vec[l].first+vec[r].first>target){
				r--;
			}else{
				l++;
			}
		}
		sort(result.begin(),result.end());
		return result;
}
};
