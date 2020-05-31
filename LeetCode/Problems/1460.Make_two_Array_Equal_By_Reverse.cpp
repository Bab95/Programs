class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        map<int,int> mmap;
        for(int i:target){
            mmap[i]++;
        }
        map<int,int> mmap2;
        for(int j:arr){
            mmap2[j]++;
        }
        for(auto it=mmap2.begin();it!=mmap2.end();++it){
            //cout<<it->first<<": "<<it->second<<endl;
            if(mmap.find(it->first)==mmap.end()){
                return false;
            }
            else{
                if(mmap[it->first]!=it->second){
                    //cout<<mmap[it->first]<<endl;
                    return false;
                }
            }
        }
        return true;
    }
};
