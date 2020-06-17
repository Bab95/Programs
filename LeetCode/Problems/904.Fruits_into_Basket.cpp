class Solution {
public:
    int totalFruit(vector<int>& tree) {
        set<int> my_set;
        unordered_map<int,int> count;
        int start = 0;
        int ans = INT_MIN;
        for(int i=0;i<tree.size();++i){
            my_set.insert(tree[i]);
            count[tree[i]]++;
            if(my_set.size()==3){
                //now start removing from the begining.....while count of one of the elements is not zero
                //also don't forget to update the ans....
                ans = max(ans,i-start);
                while(true){
                    count[tree[start]]--;
                    if(count[tree[start]]==0){
                        my_set.erase(tree[start]);
                        start+=1;
                        break;
                    }
                    start++;
                }
            }
        }
        int current = tree.size()-start;
        ans = max(ans,current);
        return ans;
    }
};
