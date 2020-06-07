class Solution {
public:
    struct mycompare{
        bool operator()(const pair<int,int>& p,const pair<int,int>& q){
            if(p.first>q.first){
                return false;
            }
            if(p.first==q.first){
                if(p.second>q.second){
                    return false;
                }
                return true;
            }
            return true;
        }
    };
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int median = arr[(n-1)/2];
        cout<<"median: "<<median<<endl;
        vector<int> res;
        res.reserve(k);
        priority_queue<pair<int,int>,vector<pair<int,int> >,mycompare> pq;
        for(int i=0;i<n;++i){
            pq.push(make_pair(abs(arr[i]-median),arr[i]));
        }

        /*for(int i=n-1;i>max(0,max(k,n-k-1));i--){
            int val = abs(arr[i]-median);
            if(val>pq.top().first){
                pq.pop();
                pq.push(make_pair(val,i));
            }
        }*/
        int i = 0;
        while(!pq.empty()&&i<k){
            //cout<<pq.top().first<<endl;
            res.push_back(pq.top().second);
            pq.pop();
            ++i;
        }
        return res;
    }
};
