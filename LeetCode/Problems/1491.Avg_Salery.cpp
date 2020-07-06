class Solution {
public:
    double average(vector<int>& salery) {
        long int ans = 0;
        int m1=salery[0],m2=salery[1];
        for(int i=0;i<salery.size();++i){
            ans+=salery[i];
            m1 = max(m1,salery[i]);
            m2 = min(m2,salery[i]);
        }

        ans = ans-m1-m2;
        int n = salery.size()-2;
        double result = (double)ans/n*1.0;
        return result;
    }
};
