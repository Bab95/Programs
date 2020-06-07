class Solution {
public:
    bool isPossible(vector<int>& gas,vector<int>& cost,int i){
        int current = gas[i]-cost[i];
        int n = gas.size();
        //now position is i+1.....
        for(int steps=1;steps<n;++steps){
            current = current+gas[(i+steps)%n]-cost[(i+steps)%n];
            if(current<0){
                return false;
            }
        }
        return true;
    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for(int i=0;i<n;++i){
            if(cost[i]<=gas[i]){
                //this could be.....
                if(isPossible(gas,cost,i)){
                    return i;
                }
            }
        }
        return -1;
    }
};
