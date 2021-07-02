// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int a,b;
        do{
            a = rand7();
        }while(a==4);

        do{
            b = rand7();
        }while(b>5);
        return a>4?b+5:b;
    }
};
