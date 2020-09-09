class FreqStack {
public:
    struct number{
        int val;
        int last_index;
        int freq;
    };
    struct num_comparator{
        bool operator()(const number& n1,const number& n2) const{
            if(n1.freq==n2.freq){
                return n1.last_index>n2.last_index;
            }
            return n1.freq>n2.freq;
        }
    };
    //set<number,decltype(num_comparator)> ss;
    set<number,num_comparator> ss;
    unordered_map<int,vector<int>> mmap;
    int index;
    FreqStack() {
        ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        index = 0;
    }

    void push(int x) {
        if(mmap.find(x)==mmap.end()){
            mmap[x].push_back(index);
            struct number n;
            n.val = x;
            n.last_index = index;
            n.freq = 1;
            ss.insert(n);
        }else{
            mmap[x].push_back(index);
            for(auto it=ss.begin();it!=ss.end();++it){
                if(it->val==x){
                    struct number nn;
                    nn.val = it->val;
                    nn.last_index = index;
                    nn.freq = it->freq + 1;
                    ss.erase(it);
                    ss.insert(nn);
                    break;
                }
            }
        }
        index++;
    }

    int pop() {
        auto top = *ss.begin();
        //int x = top->val;
        int x = top.val;
        mmap[x].pop_back();
        ss.erase(ss.begin());
        if(top.freq>1){
            struct number new_number;
            //new_number.val = top->val;
            //new_number.last_index = mmap[x][mmap[x].size()-1];
            //new_number.freq = (top->freq)-1;

            new_number.val = top.val;
            new_number.last_index = mmap[x][mmap[x].size()-1];
            new_number.freq = (top.freq)-1;
            ss.insert(new_number);
        }else{
            mmap.erase(x);
        }
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
