class Solution {
public:
    vector<int> countBits(int num) {
        if(num==0){
            return {0};
        }
        vector<int> ans(num+1,0);
        ans[0] = 0;
        ans[1] = 1;
        for(int i=2;i<=num;++i){
            if(i%2==0){
                int tmp = i/2;
                ans[i] = ans[tmp];
                int n1 = 0;
                do{
                    ans[i] = max(ans[i],ans[tmp]);
                    tmp = tmp/2;
                }while(tmp%2);
            }else{
                ans[i] = ans[i-1] + 1;
            }
        }
        return ans;
    }
};
