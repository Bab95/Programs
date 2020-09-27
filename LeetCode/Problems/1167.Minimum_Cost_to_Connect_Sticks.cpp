class Solution {
public:
    struct mycompare{
        //MIN HEAP
        bool operator()(const int& a,const int& b){
            return a>b;
        }
    };
    int connectSticks(vector<int>& sticks) {
        priority_queue<int,vector<int>,mycompare> pq;
        for(int i=0;i<sticks.size();++i){
            pq.push(sticks[i]);
        }
        int ans = 0;
        while(!pq.empty()){
            int a = pq.top();
            pq.pop();
            if(!pq.empty()){
                int b = pq.top();
                int cost = a + b;
                pq.pop();

                ans += cost;
                pq.push(cost);
            }
        }
        return ans;
    }
};
