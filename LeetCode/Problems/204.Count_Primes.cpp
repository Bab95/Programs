class Solution {
public:
    int countPrimes(int n) {
        vector<bool> primes(n+1,true);
        //primes[2] = true;
        for(int i=2;i<=sqrt(n);++i){
            for(int j=i*i;j<=n;j=j+i){
                primes[j] = false;
            }
        }
        int count = 0;
        for(int i=n-1;i>=2;i--){
            if(primes[i]){
                count++;
            }
        }
        return count;
    }
};
