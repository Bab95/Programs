class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        int current = 0;
        vector<pair<int,int> > pp;
        for(auto it : trips){
            pp.push_back(make_pair(it[1],it[0]));
            pp.push_back(make_pair(it[2],-1*it[0]));
        }
        sort(pp.begin(),pp.end());
        int k = 0;
        /*for(auto it : pp){
            cout<<it.first<<" "<<it.second<<endl;
        }*/
        for(int i=0;i<pp.size();){
            int current = pp[i].first;
            int pass = pp[i].second;
            i++;
            while(i<pp.size()&&pp[i].first==current){
                pass += pp[i].second;
                ++i;
            }
            pp[k].first = current;
            pp[k].second = pass;
            k++;
        }
        current = 0;
        for(int i=0;i<k;++i){
            current+=pp[i].second;
            if(current>capacity){
                return false;
            }
        }

        return true;
    }
};
/*
[[3,2,7],[3,7,9],[8,3,9]]
11
[[2,1,5],[3,3,7]]
4
[[2,1,5],[3,3,7]]
5
[[2,1,5],[3,5,7]]
3

*/
