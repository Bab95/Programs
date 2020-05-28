class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_map<int,int> mmap;
        //sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            mmap[arr[i]]++;
        }
        int result = 0;
        /*for(auto it=mmap.begin();it!=mmap.end();++it){
            if(mmap.count(it->first+1)){
                result += mmap[it->first+1];
            }
        }*/
        for(int i=0;i<arr.size();++i){
            if(mmap.count(arr[i]+1)){
                result++;
            }
        }
        return result;
    }
};
