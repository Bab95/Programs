class Solution {
public:
    int numberOfSteps (int num) {
        if(num==0){
            return 0;
        }
        int steps = 0;
        while(num){
            if(((num)|(num<<1))%2==0){
                steps+=1;
            }else{
                steps+=2;
            }
            num = num>>1;
        }
        return steps-1;
    }
};
