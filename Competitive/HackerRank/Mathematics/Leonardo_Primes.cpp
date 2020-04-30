#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the primeCount function below.
 */
static int primeCount(long n) {
    /*
     * Write your code here.
     */
     /*if(n<2){
         return 0;
     }
     int max_factors = 0;
    vector<long> primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    for(long i=n;i>2;i--){
        long num = i;
        int pc = 0;
        cout<<i<<" :";
        for(int j=0;j<15;j++){
            //cout<<j<<" ";
            if(num==0){
                break;
            }
            if(num%primes[j]==0){
                while(num>0&&num%primes[j]==0){
                    num = num/primes[j];
                }
                pc++;
            }
        }
        cout<<pc<<endl;
        max_factors = max(pc,max_factors);
    }
    return max_factors;
    */
    vector<long> primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    if(n==1) return 0;
    long multi = 1;
    int count =0;
    for(int i =0;i<primes.size();i++){

          multi*=primes[i];
          if(multi<=n) count ++;
          else break;
  }
  return count;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        long n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = primeCount(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
