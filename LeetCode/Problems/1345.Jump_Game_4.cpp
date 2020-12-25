#define speed ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef unordered_multimap<int,int>::iterator itr;
class Solution {
public:
    Solution(){
        speed
    }
    int minJumps(vector<int>& a) {
        if(a.size()<=1){
            return 0;
        }
        vector<int> arr;
        for(int i=0;i<a.size();i++){
            int key = a[i];
            arr.push_back(key);
            int j = i+1;
            while(j<a.size()&&key==a[j]){
                j++;
            }
            if(j!=i+1){
                arr.push_back(key);
            }
            //if(j>=i+3){
            //    arr.push_back(key);
            //}
            i = j-1;
        }
        int n = arr.size();
        unordered_multimap<int,int> mmap;
        for(int i=0;i<arr.size();++i){
            mmap.insert({arr[i],i});
        }
        //for(auto it=mmap.begin();it!=mmap.end();++it){
        //    cout<<it->first<<" "<<it->second<<endl;
        //}
        queue<int> q;
        q.push(0);
        int ans = INT_MAX;
        vector<bool> visited(n,false);
        visited[0] = true;
        int level = 0;
        while(!q.empty()){
            int s = q.size();
            for(int i=0;i<s;++i){
                int index = q.front();
                q.pop();
                if(index==n-1){
                    return level;
                }
                pair<itr,itr> it = mmap.equal_range(arr[index]);
                itr it1 = it.first;
                while(it1!=it.second){
                    pair<int,int> tmp = *it1;
                    if(!visited[tmp.second]){
                        visited[tmp.second] = true;
                        q.push(tmp.second);
                    }
                    it1++;
                }
                if(index>0&&!visited[index-1]){
                    visited[index-1] = true;
                    q.push(index-1);
                }
                if(index<n-1&&!visited[index+1]){
                    q.push(index+1);
                    visited[index+1] = true;
                }
            }
            level++;
        }
        return -1;
    }
};
