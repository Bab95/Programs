/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        stack<int> stk;
        for(int i=0;i<n;++i){
            stk.push(i);
        }
        while(!stk.empty()){
            int a = stk.top();
            stk.pop();
            if(stk.empty()){
                for(int i=0;i<n;++i){
                    if(i==a){
                        continue;
                    }
                    if(knows(a,i)){
                        return -1;
                    }
                }
                return a;
            }
            int b = stk.top();
            stk.pop();
            if(knows(a,b)){
                stk.push(b);
            }else if(knows(b,a)){
                stk.push(a);
            }
        }
        return -1;
    }
};
