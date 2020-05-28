class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> stk;
    int minElement;
    MinStack() {
        minElement = INT_MAX;
    }

    void push(int x) {
        stk.push(x);
        if(x<minElement){
            minElement = x;
        }
    }

    void pop() {
        int tmp = stk.top();
        stk.pop();
        if(tmp==minElement){
            stack<int> tmp_stk;
            int nextMin = INT_MAX;
            while(!stk.empty()){
                nextMin = min(stk.top(),nextMin);
                tmp_stk.push(stk.top());
                stk.pop();
            }
            minElement = nextMin;
            while(!tmp_stk.empty()){
                stk.push(tmp_stk.top());
                tmp_stk.pop();
            }
        }
    }

    int top() {
        if(stk.empty()){
            return -1;
        }
        return stk.top();
    }

    int getMin() {
        return minElement;
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
