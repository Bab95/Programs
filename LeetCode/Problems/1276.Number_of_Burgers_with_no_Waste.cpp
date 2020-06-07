class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        if(tomatoSlices%2==1){
            return {};
        }
        long long int t = (long long int)tomatoSlices;
        long long int c = (long long int)cheeseSlices;
        double a = (t-2*c)/2;
        if(a>=0&&(a-(long long int)a)==0){
            long long int x = (long long int)a;
            long long int b = (t - 4*x)/2;
            if(b>=0)
                return {(int)x,(int)b};
            else if(b<0){
                return {};
            }
        }
        return {};
    }
};
