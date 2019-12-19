class Solution {
public:
    int max(int a,int b){
        return a>b?a:b;
    }
    int min(int a,int b){
        return a<b?a:b;
    }
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n-1;
        int water = 0;
        while(l<r){
           water = max(water,(r-l)*min(height[l],height[r]));
           if(height[l]>height[r]){
               r--;
           }else{
               l++;
           }
        }
        return water;
    }
};
