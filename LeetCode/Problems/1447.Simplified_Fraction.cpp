class Solution {
public:

    string simplify(int a,int b){
        int d = __gcd(a,b);
        a = a/d;
        b = b/d;
        string ans;
        ans.append(to_string(a));
        ans.push_back('/');
        ans.append(to_string(b));
        return ans;
    }
    vector<string> simplifiedFractions(int n) {
        map<string,int> ans;
        for(int num=1;num<n;num++){
            for(int denom=num+1;denom<=n;denom++){
                string tmp = simplify(num,denom);
                if(ans.find(tmp)==ans.end()){
                    ans[tmp] = 1;
                }
            }
        }
        vector<string> result;
        for(auto it=ans.begin();it!=ans.end();++it){
            result.push_back(it->first);
        }
        return result;
    }
};
