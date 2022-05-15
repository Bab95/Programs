class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int radius = 0;
        for (int i=0;i<houses.size();i++){
            int nearest = lower_bound(heaters.begin(), heaters.end(), houses[i]) - heaters.begin();

            if (nearest == heaters.size()){
                nearest--;
            }

            if (nearest == 0){
                radius = max(radius, abs(heaters[nearest]-houses[i]));
            }else {
                // left because it will be either equal or greater than the given value
                // that's why we need to check only left side. not right
                int left = abs(heaters[nearest-1]-houses[i]);
                int current = abs(heaters[nearest]-houses[i]);
                radius = max(radius, min(left, current));
            }
        }
        return radius;
    }
};
