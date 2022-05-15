class Solution {
public:
    int countHomogenous(string s) {
        int i = 0;
        int result = 0;
        int m = 1000000007;
        while (i<s.length()){
            char current = s[i];
            int j = i;
            long long int count = 0;
            while (j<s.length() && current == s[j]){
                count++;
                j++;
                i++;
            }
            //cout << current <<" <-> " << count <<endl;
            long long int x = 0;
            if (count%2 == 1){
                x = (count+1)/2;
                x = x*count;
                x = x%m;
            }else{
                x = count/2;
                x = x*(count+1);
                x = x%m;
            }
            result += x;

            if (result > m){
                result = result%m;
            }
        }
        return result;
    }
};
