class Solution {
public:
    int nthUglyNumber(int n) {
        int count = 0;
        set<long int> s;
        s.insert(1);
        long int current = 1;
        while(count<n){
            current = *(s.begin());
            s.erase(s.begin());
            long int a = current*2;
            long int b = current*3;
            long int c = current*5;
            s.insert(a);
            s.insert(b);
            s.insert(c);
            count++;
        }
        return current;
    }
};
