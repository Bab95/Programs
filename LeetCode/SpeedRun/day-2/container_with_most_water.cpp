class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int l = 0;
        int r = height.size()-1;
        while(l<r){
            int current = (r-l)*min(height[l],height[r]);
            ans = max(current,ans);
            if(height[r]<height[l]){
                r--;
            }else{
                ++l;
            }
        }
        return ans;
    }
};
