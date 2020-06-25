class Solution {
public:
    bool similar(vector<int>& h1,vector<int>& h2){
        int i = 0;
        while(i<h1.size()){
            if(h1[i]>0&&h2[i]>0){
                return true;
            }
            i++;
        }
        return false;
    }
    int maxProduct(vector<string>& words) {
        vector<pair<string,pair<int,vector<int> > > > mmap;
        for(auto w : words){
            vector<int> hash(26,0);
            for(auto c : w){
                hash[c-'a']++;
            }
            mmap.push_back(make_pair(w,make_pair(w.length(),hash)));
        }
        auto mycompare = [](const pair<string,pair<int,vector<int>>>& p,const pair<string,pair<int,vector<int>>>& q){
            if(p.second.first<q.second.first){
                return true;
            }
            return false;
        };
        //sort(mmap.begin(),mmap.end(),mycompare);
        int product = 0;
        for(int i=mmap.size()-1;i>=1;i--){
            for(int j=i-1;j>=0;j--){
                if(!similar(mmap[i].second.second,mmap[j].second.second)){
                    product = max(product, mmap[i].second.first*mmap[j].second.first);
                }
            }
        }
        return product;
    }
};
