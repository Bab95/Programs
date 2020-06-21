class Solution {
public:
    static bool mycompare(const pair<int,int>& p1,const pair<int,int>& p2){
        if(p1.first<p2.first){
            return true;
        }
        if(p1.first==p2.first){
            if(p1.second<p2.second){
                return true;
            }
        }
        return false;
    }
    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int,int> > brr(arr.size());
        for(int i=0;i<n;++i){
            int x = arr[i];
            int count = 0;
            while(x){
                count += x&1;
                x = x>>1;
            }
            brr[i].first = count;
            brr[i].second = arr[i];
        }

        sort(brr.begin(),brr.end(),mycompare);

        for(int i=0;i<n;++i){
            arr[i] = brr[i].second;
        }
        return arr;
    }
};
