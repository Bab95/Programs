class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        queue<int> q;
        int p=0,n=0;
        int ans = 0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]==0){
                if(n%2==0){
                    ans = max(ans,(int)q.size());
                }else{
                    int qs = q.size();
                    while(!q.empty()){
                        int tmp = q.front();
                        q.pop();
                        qs--;
                        if(tmp<0){
                            ans = max(ans,qs);
                            break;
                        }
                    }
                }
                p = 0;
                n = 0;
                while(!q.empty()){
                    q.pop();
                }
                continue;
            }else if(nums[i]>0){
                p++;

            }else if(nums[i]<0){
                n++;

            }
            q.push(nums[i]);
            if(n%2==0){
                ans = max(ans,(int)q.size());
            }
        }
        if(n%2==0){
            ans = max(ans,(int)q.size());
        }else{
            int qs = q.size();
            while(!q.empty()){
                int tmp = q.front();
                q.pop();
                qs--;
                if(tmp<0){
                    ans = max(ans,qs);
                    break;
                }
            }
        }
        return ans;
    }
};
