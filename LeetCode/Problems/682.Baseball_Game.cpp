#include <stack>
class Solution {
public:
    int convert2Int(string &s){
        int res = 0;
        int sign = 1;
        int start = 0;
        if(s[0]=='-'){
            sign = -1;
            start = 1;
        }
        for(int i=start;i<s.size();i++){
            res = res*10+((int)s[i]-48);
        }
        res = res*sign;
        return res;
    }
    int calPoints(vector<string>& ops) {
        stack<int> s;
        int sum = 0;
        for(int i=0;i<ops.size();i++){
            if(ops[i]=="C"){
                int tmp = s.top();
                s.pop();
                sum = sum-tmp;
            }else if(ops[i]=="D"){
                int tmp = s.top();
                tmp = 2*tmp;
                sum = sum+tmp;
                s.push(tmp);
            }else if(ops[i]=="+"){
                int v1 = s.top();
                s.pop();
                int v2 = s.top();
                s.push(v1);
                sum = sum+v1+v2;
                s.push(v1+v2);
            }else{
                int val = convert2Int(ops[i]);
                s.push(val);
                sum+=val;
            }
        }
        return sum;
    }
};
