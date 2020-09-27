class Solution {
public:
    int compareVersion(string version1, string version2) {
        queue<int> q1,q2;
        stringstream str1(version1),str2(version2);
        string version;
        while(getline(str1,version,'.')){
            q1.push(stoi(version));
        }
        while(getline(str2,version,'.')){
            q2.push(stoi(version));
        }
        while(!q1.empty()&&!q2.empty()){
            if(q1.front()>q2.front()){
                return 1;
            }else if(q1.front()<q2.front()){
                return -1;
            }else{
                q1.pop();
                q2.pop();
            }
        }
        if(q1.empty()&&!q2.empty()){
            while(!q2.empty()&&q2.front()==0){
                q2.pop();
            }
            if(!q2.empty()){
                return -1;
            }else{
                return 0;
            }
        }else if(q2.empty()&&!q1.empty()){
            while(!q1.empty()&&q1.front()==0){
                q1.pop();
            }
            if(!q1.empty()){
                return 1;
            }else{
                return 0;
            }
        }
        return 0;
    }
};
