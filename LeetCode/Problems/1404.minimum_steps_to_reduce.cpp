class Solution {
public:
    void add1(string& s){
        int carry = 1;
        int i = s.length()-1;
        while(i>=0&&carry){
            int sum = ((int)s[i]-48)+carry;
            carry = sum/2;
            sum = sum%2;
            s[i] = (char)(sum+48);
            i--;
        }
        if(carry){
            string tmp = "1";
            s.insert(0,tmp);
        }
        //return s;
    }
    int min_steps(string s,int nums_steps){
        if(s=="1"){
            return nums_steps;
        }
        if(s[s.length()-1]=='1'){
            add1(s);
            return min_steps(s,nums_steps+1);
        }
        if(s[s.length()-1]=='0'){
            return min_steps(s.substr(0,s.length()-1),nums_steps+1);
        }
        return -1;
    }
    int numSteps(string s) {
        int num_steps = 0;
        return min_steps(s,num_steps);
    }
};