class Solution {
public:
    int len(int n){
        int res = 0;
        while(n){
            n /= 10;
            res++;
        }
        return res;
    }
    vector<int> numsSameConsecDiff(int N, int k) {
        queue<int> q;
        for(int i=1;i<10;++i){
            q.push(i);
        }
        vector<int> res;
        while(!q.empty()){
            int current = q.front();
            q.pop();
            if(len(current)==N){
                res.push_back(current);
            }else{
                int last = current%10;
                int new_last = 0;
                if(k==0){
                    q.push(current*10+last);
                }else{
                    if(last+k<10){
                        new_last = last + k;
                        q.push(current*10+new_last);
                    }
                    if(last-k>=0){
                        new_last = last-k;
                        q.push(current*10+new_last);
                    }
                }
            }
        }
        if(N==1){
            res.push_back(0);
        }
        return res;
    }
};
