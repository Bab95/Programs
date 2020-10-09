/*
Recursive Solution Slow..................Fails for very large inputs
*/
class Solution {
public:
    void find_numbers(vector<string>& digits,int& n,int index,long int current,unordered_set<int>& numbers){
        if(current>=n){
            if(current==n){
                numbers.insert(current);
            }
            return;
        }
        if(current<n&&current!=0){
            numbers.insert(current);
        }
        for(int i=index;i<digits.size();++i){
            if((current*10+(digits[i][0]-'0'))<=n){
                find_numbers(digits,n,index,current*10+(digits[i][0]-'0'),numbers);
            }
            find_numbers(digits,n,i+1,current,numbers);
        }

    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {

        unordered_set<int> numbers;
        int i = 0;
        long int current = 0;
        find_numbers(digits,n,i,current,numbers);
        return numbers.size();
    }
};
