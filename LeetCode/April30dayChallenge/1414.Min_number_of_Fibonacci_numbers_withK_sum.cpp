class Solution {
public:
    vector<int> generatefibs(int k){
        int a = 0;
        int b = 1;
        vector<int> fibs;
        fibs.push_back(1);
        while(true){
            int f = a+b;
            if(f>k){
                break;
            }
            a = b;
            b = f;
            fibs.push_back(f);
        }
        return fibs;
    }
    void print(vector<int>& fib){
        for(int i=0;i<fib.size();++i){
            cout<<fib[i]<<" ";
        }
    }
    int findMinFibonacciNumbers(int k) {
        int ans = 0;
        vector<int> fibs = generatefibs(k);
        int i = fibs.size()-1;
        while(true){
            ans+=k/fibs[i];
            k = k%fibs[i];
            if(k==0){
                return ans;
            }
            i--;
        }
        return ans;
    }
};
