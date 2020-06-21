class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num==0){
            return false;
        }
        int ans = 0;
        int tmp = num;
        while(num%2==0){
            ans+=num/2;
            num = num/2;
        }
        
        for(int i=1;i<num;i++){
            /*if(i==sqrt(num)&&ans==1){
                //its a prime....
                return false;
            }*/
            if(tmp%i==0){
                ans+=i;
            }
        }
        if(ans==tmp){
            return true;
        }
        return false;
    }
};
