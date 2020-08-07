class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        //forward.....
        int n = distance.size();
        int _forward_distance = 0;
        for(int i=start;i!=destination;i=(i+1)%n){
            _forward_distance+=distance[i];
        }
        //backward.....
        int _backward_distance = 0;
        for(int i=start;i!=destination;){
            if(i==0){
                i = n-1;
            }else{
                i--;
            }
            _backward_distance+=distance[i];

        }
        return min(_forward_distance,_backward_distance);
    }
};
