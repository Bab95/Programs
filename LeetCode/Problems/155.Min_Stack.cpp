class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> stk;
    unordered_map<int,int> hash_table;
    int current_min;
    MinStack() {
        current_min = INT_MAX;
    }

    void push(int x) {
        stk.push(x);
        if(hash_table.find(x)==hash_table.end()){
            hash_table[x] = 1;
        }else{
            hash_table[x] = hash_table[x] + 1;
        }
        if(current_min>x){
            current_min =  x;
        }
    }

    void pop() {
        int current_element;
        if(!stk.empty()){
            current_element = stk.top();
            stk.pop();
            if(current_element==current_min){
              if(hash_table[current_min]==1){
                  hash_table[current_min] = 0;
                  unordered_map<int,int>::iterator itr;
                  current_min = INT_MAX;
                  for(itr=hash_table.begin();itr!=hash_table.end();itr++){
                      if(itr->second!=0){
                          current_min = min(current_min,itr->first);
                      }
                  }
              }else{
                  hash_table[current_min] = hash_table[current_min] - 1;
              }
            }else{
                hash_table[current_element] = hash_table[current_element] - 1;
            }
            cout<<current_element<<endl;
            return;
        }
        cout<<"stack was empty"<<endl;
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return current_min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
