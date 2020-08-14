class Solution {
public:
    int numberOfSteps (int num) {
        if(num<=3){
            return num;
        }
        if(num%2==1){
            return 1 + numberOfSteps(num-1);
        }
        return 1 + numberOfSteps(num/2);
    }
};
