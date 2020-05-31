#define M 1000000007
class Solution {
public:
    int maxArea(int h, int w, vector<int>& hor, vector<int>& ver) {
        sort(hor.begin(),hor.end());
        sort(ver.begin(),ver.end());
        vector<int> arh;
        arh.push_back(hor[0]-0);
        for(int i=1;i<hor.size();++i){
            arh.push_back(hor[i]-hor[i-1]);
        }
        vector<int> vrh;
        vrh.push_back(ver[0]-0);
        for(int i=1;i<ver.size();++i){
            vrh.push_back(ver[i]-ver[i-1]);
        }
        vrh.push_back(w-ver[ver.size()-1]);
        arh.push_back(h-hor[hor.size()-1]);
        sort(arh.begin(),arh.end());
        sort(vrh.begin(),vrh.end());

        unsigned long long int ans = (unsigned long long int)arh[arh.size()-1]*(unsigned long long int)vrh[vrh.size()-1];
        ans = ans%M;
        return (int)ans;
    }
};
