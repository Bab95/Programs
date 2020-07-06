class Solution {
public:
    static bool mycompare(string& x,string& y){
        string xy = x;
        xy.append(y);
        string yx = y;
        yx.append(x);
        if(xy>yx){
            return true;
        }
        return false;
    }
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> arr(n);
        for(int i=0;i<n;++i){
            arr[i] = to_string(nums[i]);
        }
        sort(arr.begin(),arr.end(),mycompare);
        string ans;
        for(int i=0;i<arr.size();++i){
            ans += arr[i];
        }
        int i = 0;
        while(i<ans.size()&&ans[i]=='0'){
            ++i;
        }
        if(i==ans.length()){
            return "0";
        }else{
            return ans.substr(i,ans.length()-i);
        }
        return ans;
    }
};
