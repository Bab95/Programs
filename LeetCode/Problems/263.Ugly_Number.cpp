class Solution {
public:
    bool isUgly(int num) {
        if(num<=0){
            return false;
        }
        while(num&&!(num%2)){
            num = num/2;
        }
        cout<<num<<endl;
        while(num&&!(num%3)){
            num = num/3;
        }
        cout<<num<<endl;
        while(num&&!(num%5)){
            num = num/5;
        }
        cout<<num<<endl;
        if(num!=1){
            return false;
        }
        return true;
    }
};
