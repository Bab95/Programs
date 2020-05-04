class Solution {
public:
    int findComplement(int num) {
        vector<int> arr;
        while(num){
            arr.push_back(num%2);
            num = num/2;
        }
        for(int i=0;i<arr.size();++i){
            if(arr[i]==1){
                arr[i] = 0;
            }else{
                arr[i] = 1;
            }
        }
        int ans = 0;
        for(int i=0;i<arr.size();++i){
            ans = ans + arr[i]*((int)pow(2,i));
        }
        return ans;
    }
};
