class Solution {
public:
    int max(int a,int b){
        return a>b?a:b;
    }
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int i = 0;
        int max_area = 0;
        int current_area = 0;
        while(i<heights.size()){
            if(s.empty()||heights[s.top()]<=heights[i]){
                s.push(i++);
            }else{
                int s_top = s.top();
                s.pop();
                current_area = (s.empty())?heights[s_top]*i:heights[s_top]*(i-s.top()-1);
                max_area = max(current_area,max_area);
            }
        }

        while(!s.empty()){
            int s_top = s.top();
            s.pop();

            if(s.empty()){
                current_area = heights[s_top]*i;
            }else{
                current_area = heights[s_top]*(i-s.top()-1);
            }
            max_area = max(max_area,current_area);
        }

        return max_area;
    }
};
