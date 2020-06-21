class MajorityChecker {
public:
    unordered_map<int,vector<int> > mmap;
    vector<int> brr;
    MajorityChecker(vector<int>& arr) {
        for(int i=0;i<arr.size();++i){
            if(mmap.find(arr[i])==mmap.end()){
                mmap[arr[i]] = vector<int>(1,i);
            }else{
                mmap[arr[i]].push_back(i);
            }
        }
        brr = arr;
    }

    int query(int left, int right, int threshold) {
        for(int i=0;i<14;++i){
            int r_index = rand()%(right-left+1) + left;
            int start_index = lower_bound(mmap[brr[r_index]].begin(),mmap[brr[r_index]].end(),left)-mmap[brr[r_index]].begin();
            int end_index = upper_bound(mmap[brr[r_index]].begin(),mmap[brr[r_index]].end(),right)-mmap[brr[r_index]].begin();
            if(end_index-start_index>=threshold){
                return brr[r_index];
            }
        }
        return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
