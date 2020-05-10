//MIN HEAP SOLUTION......
class Solution {
public:
    struct compare
    {
        bool operator()(pair<int,pair<int,int> >& p1,pair<int,pair<int,int> >& p2){
            if(p1.first<p2.first){
                //already in place don't swap....
                return false;
            }
            return true;
        }
    };
    int min(int a,int b){
        return a<b?a:b;
    }
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        if(nums1.empty() || nums2.empty() || k == 0)
            return res;
        int x = min(nums1.size(),k);
        priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >, compare> pq;
        for(int i=0;i<x;++i){
            pq.push(make_pair(nums1[i]+nums2[0],make_pair(i,0)));
            //cout<<pq.top().first<<" "<<pq.top().second<<endl;
        }
        while(k>0&&!pq.empty()){
            //cout<<pq.top().first<<endl;//<<" "<<pq.top().second<<endl;
            int id1 = pq.top().second.first;
            int id2 = pq.top().second.second;
            pq.pop();
            res.push_back({nums1[id1],nums2[id2]});
            if(id2+1<nums2.size()){
                pq.push(make_pair(nums1[id1]+nums2[id2+1],make_pair(id1,id2+1)));
            }
            k--;
        }
        return res;
    }
};



//MAX HEAP SOLUTION.....
class Solution {
public:
    struct mycompare{
        bool operator()(pair<int,int> p1,pair<int,int> p2){
            if(p1.first+p1.second<p2.first+p2.second){
                return true;
            }
            return false;
        }
    };
    int min(int a,int b){
        return a<b?a:b;
    }
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int> > ans;
        ans.reserve(k);
        priority_queue<pair<int,int>,vector<pair<int,int> >,mycompare> pq;
        //need to iterate till k only as k smallest pair will occur eventually till k in both arrays.....
        for(int i=0;i<min(nums1.size(),k);++i){
            for(int j=0;j<min(nums2.size(),k);++j){
                if(pq.size()<k){
                    pq.push(make_pair(nums1[i],nums2[j]));
                }else if(nums1[i]+nums2[j]<pq.top().first+pq.top().second){
                    pq.pop();
                    pq.push(make_pair(nums1[i],nums2[j]));
                }
            }
        }
        while(!pq.empty()){
            ans.push_back({pq.top().first,pq.top().second});
            pq.pop();
        }
        return ans;
    }
};
