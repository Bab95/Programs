class Solution {
public:
    vector<int> arr;
    int sum = 0;
    Solution(vector<int>& w) {
        arr.reserve(w.size());
        for(int i=0;i<w.size();++i){
            sum += w[i];
            arr.push_back(w[i]);
        }
        /*for(int i=0;i<arr.size();++i){
            cout<<arr[i]<<" ";
        }
        cout<<endl;*/
    }
    int pickIndex() {
        int ans = rand()%sum;
        //cout<<ans<<" ";
        int current = 0;
        for(int i=0;i<arr.size();++i){
            if(ans<current+arr[i]){
                ans = i;
                break;
            }else{
                current += arr[i];
            }
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
