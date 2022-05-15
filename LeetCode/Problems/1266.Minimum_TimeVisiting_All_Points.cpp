class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        vector<int> current = points[0];
        int result = 0;
        for (int i=1;i<points.size();i++){
            int distance = max(abs(points[i][0] - current[0]), abs(points[i][1] - current[1]));
            result += distance;
            current = points[i];
        }
        return result;
    }
};
