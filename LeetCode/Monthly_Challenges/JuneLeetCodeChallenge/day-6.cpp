class Solution {
public:
    static bool compare(const vector<int>& v1,const vector<int>& v2){
        if(v1[0]>v2[0]){
            return true;
        }
        if(v1[0]==v2[0]&&v1[1]<v2[1]){
            return true;
        }
        return false;
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),compare);
        /*for(int i=0;i<people.size();++i){
            cout<<people[i][0]<<" "<<people[i][1]<<endl;
        }*/
        for(int i=1;i<people.size();++i){
            if(people[i][0]==people[i-1][0]){
                continue;
            }else{
                //need to perform shift....
                vector<int> tmp = people[i];
                //put it at its position....
                int k = i;
                while(k>tmp[1]){
                    people[k] = people[k-1];
                    k--;
                }
                people[k] = tmp;
            }
        }
        return people;
    }
};
