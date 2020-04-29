class FirstUnique {
public:
    queue<int> q;
    unordered_map<int,int> mmap;
    FirstUnique(vector<int>& nums) {
        for(int i=0;i<nums.size();++i){
            q.push(nums[i]);
            mmap[nums[i]]++;
        }
    }

    int showFirstUnique() {
        if(mmap[q.front()]==1){
            return q.front();
        }else{
            while(!q.empty()){
                int tmp = q.front();
                if(mmap[tmp]==1){
                    return tmp;
                }
                q.pop();
            }
        }
        return -1;
    }

    void add(int value) {
        q.push(value);
        mmap[value] += 1;
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
