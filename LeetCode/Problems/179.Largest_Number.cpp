class Solution {
public:
    static bool myCompare(string s1,string s2){
        string xy = s1.append(s2);
        string yx = s2.append(s1);
        return xy.compare(yx)>=0?1:0;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> Nums;
        Nums.reserve(nums.size());
        for(int x : nums){
            Nums.push_back(to_string(x));
        }

        sort(Nums.begin(),Nums.end(),myCompare);
        string res;
        int i = 0;
        while(i<Nums.size()-1&&Nums[i]=="0"){
            ++i;
        }
        for(;i<Nums.size();++i){
            res.insert(res.end(),Nums[i].begin(),Nums[i].end());
        }
        return res;
    }
};
