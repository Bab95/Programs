class Solution {
public:
    int _minScoreTriangulation(vector<int>& A,int ind) {
        int triangles = A.size()-2;
        int ans = 0;
        int n = A.size();
        int j = 1;
        for(int i=1;i<=triangles;++i){
            ans += (A[ind%n]*A[(ind+j)%n]*A[(ind+j+1)%n]);
            j+=1;
        }
        return ans;
    }
    int find(vector<int>& points,int _start){
        if(points.size()==3){
            return points[0]*points[1]*points[2];
        }
        if(points.size()==4){
            int a = points[0]*points[2]*(points[1]+points[3]);
            int b = points[1]*points[3]*(points[0]+points[2]);
            return min(a,b);
        }
        int n = points.size();
        int t = 0;
        vector<int> rem;
        int current = 0;
        int start = _start;
        while(t<n/2){
            t++;
            current += (points[start%n]*points[(start+1)%n]*points[(start+2)%n]);
            start = (start+2)%n;
        }
        t = 0;
        while(t<(n+1)/2){
            t++;
            rem.push_back(points[_start%n]);
            _start = (_start + 2)%n;
        }
        return current + find(rem,0);
    }
    int minScoreTriangulation(vector<int>& A) {
        if(A.size()==3){
            return A[0]*A[1]*A[2];
        }
        int ans = INT_MAX;
        if(A.size()%2==0){
            ans = min(find(A,0),find(A,1));
        }
        for(int i=0;i<A.size();++i){
            ans = min(ans,_minScoreTriangulation(A,i));
            ans = min(ans,find(A,i));
        }

        return ans;
    }
};
