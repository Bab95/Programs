class Solution {
public:
    vector<int> split(string& s){
        string current;
        vector<int> ans;
        for(int i=0;i<s.length();++i){
            if(s[i]=='.'){
                ans.push_back(stoi(current));
                current.clear();
            }else{
                current.push_back(s[i]);
            }
        }
        ans.push_back(stoi(current));
        return ans;
    }
    void print(vector<int>& arr){
        for(auto it:arr){
            cout<<it<<endl;
        }
    }
    int compareVersion(string version1, string version2) {
        vector<int> v1 = split(version1);
        vector<int> v2 = split(version2);
        /*print(v1);
        cout<<"-----"<<endl;
        print(v2);
        */int i = 0;
        while(i<v1.size()&&i<v2.size()){
            if(v1[i]==v2[i]){
                ++i;
                continue;
            }else if(v1[i]<v2[i]){
                return -1;
            }else if(v1[i]>v2[i]){
                return 1;
            }
            ++i;
        }
        if(i==v1.size()&&i==v2.size()){
            return 0;
        }else if(i==v1.size()){
            while(i<v2.size()){
                if(v2[i]>0){
                    return -1;
                }
                ++i;
            }
            return 0;
        }else if(i==v2.size()){
            while(i<v1.size()){
                if(v1[i]>0){
                    return 1;
                }
                ++i;
            }
            return 0;
        }
        return 0;
    }
};
