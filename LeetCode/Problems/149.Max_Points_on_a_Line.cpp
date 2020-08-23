class Solution {
public:
    int _gcd(int a,int b){
        if(b==0){
            return a;
        }
        return _gcd(b,a%b);
    }
    struct _hash{
        size_t operator () (const pair<int,int>& p) const {
            return p.first ^ p.second;
        }
    };
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;

        for(int i=0;i<n;++i){
            unordered_map<pair<int,int>,int,_hash> mmap;
            int vertical = 0;
            int overlapping = 0;
            int current_max = 0;
            for(int j=i+1;j<n;++j){
                if(points[i][0]==points[j][0]&&points[i][1]==points[j][1]){
                    overlapping++;
                    continue;
                }else if(points[i][0]==points[j][0]){
                    vertical++;
                }else{
                    int x = points[i][0]-points[j][0];
                    int y = points[i][1]-points[j][1];
                    int g = _gcd(x,y);
                    x /= g;
                    y /= g;
                    pair<int,int> slope;
                    slope = make_pair(x,y);
                    mmap[slope]++;
                    current_max = max(current_max,mmap[slope]);
                }

                current_max = max(current_max,vertical);
            }
            /*
            for(auto it=mmap.begin();it!=mmap.end();++it){
                    cout<<it->first.first<<","<<it->first.second<<"-->"<<it->second<<endl;
                }
                */
            ans = max(current_max+overlapping+1,ans);
        }
        return ans;
    }
};
