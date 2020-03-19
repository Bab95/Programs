class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int> > pq;
    int size = 0;
    int max_size = -1;
    KthLargest(int k, vector<int>& nums) {
        max_size = k;
        int n = nums.size();
        for(int i=0;i<n&&i<k;++i){
            pq.push(nums[i]);
            ++size;
        }
        for(int i=k;i<n;++i){
            if(nums[i]>pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
    }

    int add(int val) {
        if(pq.empty()){
            pq.push(val);
            ++size;
        }else if(size<max_size){
            pq.push(val);
            ++size;
        }else if(val>pq.top()){
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
