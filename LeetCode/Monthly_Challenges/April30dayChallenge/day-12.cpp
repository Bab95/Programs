class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i=0;i<stones.size();++i){
            pq.push(stones[i]);
        }
        while(!pq.empty()){
            int x = pq.top();
            pq.pop();
            int y = INT_MIN;;
            if(!pq.empty()){
                y = pq.top();
                pq.pop();
            }else{
                return x;
            }
            if(x!=y){
                int tmp = x-y;
                pq.push(tmp);
            }
        }
        return 0;
    }
};