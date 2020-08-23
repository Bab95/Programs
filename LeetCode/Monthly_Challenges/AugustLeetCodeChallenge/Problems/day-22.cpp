class Solution {
public:
    unordered_map<int,vector<int> > mmap_x,mmap_y;
    int rectangles = 0;
    vector<int> A;
    int area(vector<int>& rect){
        return (rect[2]-rect[0]+1)*(rect[3]-rect[1]+1);
    }
    Solution(vector<vector<int>>& rects) {
        srand (time(NULL));
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        for(int i=0;i<rects.size();++i){
            int x1 = rects[i][0];
            int x2 = rects[i][2];
            int y1 = rects[i][1];
            int y2 = rects[i][3];
            for(int i=min(x1,x2);i<=max(x1,x2);++i){
                mmap_x[rectangles].push_back(i);
            }
            for(int i=min(y1,y2);i<=max(y1,y2);++i){
                mmap_y[rectangles].push_back(i);
            }
            if(i==0){
                A.push_back(area(rects[i]));
            }else{
                A.push_back(A[A.size()-1]+area(rects[i]));
            }
            rectangles++;
        }
    }


    vector<int> pick() {
        int ar = rand()%A[A.size()-1];
        auto it = upper_bound(A.begin(),A.end(),ar);
        int rec_no = it-A.begin();
        int _x = rand()%(mmap_x[rec_no].size());
        int _y = rand()%(mmap_y[rec_no].size());
        return {mmap_x[rec_no][_x],mmap_y[rec_no][_y]};
    }

};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
