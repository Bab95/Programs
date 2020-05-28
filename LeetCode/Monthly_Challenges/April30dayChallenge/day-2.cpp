class Solution {
public:
    vector<int> digits(int n){
        vector<int> result;
        while(n){
            int rem = n%10;
            result.push_back(rem);
            n = n/10;
        }
        return result;
    }
    bool isHappyutil(int n,unordered_map<int,int>& m){
        vector<int> result = digits(n);
        int sum = 0;
        for(int i=0;i<result.size();i++){
            sum += (result[i]*result[i]);
        }
        if(sum==1){
            return true;
        }
        if(m.find(sum)!=m.end()){
            return false;
        }
        m[sum] = 1;
        return isHappyutil(sum,m);
    }
    bool isHappy(int n) {
        if(n==1){
            return true;
        }
        unordered_map<int,int> m;
        m[n] = 1;
        vector<int> digit = digits(n);
        int sum = 0;
        for(int i=0;i<digit.size();i++){
            sum += (digit[i]*digit[i]);
        }
        return isHappyutil(n,m);
    }
};
