class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        long int new_number = 0;
        long int old_number = x;
        while(x){
            int rem = x%10;
            new_number = new_number*10+rem;
            x = x/10;
        }
        if(new_number==old_number){
            return true;
        }
        cout<<new_number<<endl;
        return false;
    }
};
