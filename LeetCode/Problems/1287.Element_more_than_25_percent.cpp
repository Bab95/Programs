class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int ans = 0;

        for(int i=0;i<arr.size();){
            int current = arr[i];
            int count = 0;
            while(i<arr.size()&&arr[i]==current){
                i++;
                count++;
            }
            if(count>arr.size()/4){
                return current;
            }
        }
        return -1;
    }
};
