class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> arr(m);
        for(int i=0;i<m;++i){
            arr[i] = i+1;
        }
        vector<int> result;
        //vector<int>::iterator itr= arr.begin();
        for(int i=0;i<queries.size();++i){
            int ele = queries[i];
            int index = 0;
            for(auto it=arr.begin();it!=arr.end();++it){
                if(*it==ele){
                    arr.erase(it);
                    result.push_back(index);
                    break;
                }
                ++index;
            }
            arr.insert(arr.begin(),ele);
            //itr++;
            //print(arr);
            
        }
        return result;
    }
    void print(vector<int>& arr){
        for(int x:arr){
            cout<<x<<" ";
        }
        cout<<endl;
    }
};