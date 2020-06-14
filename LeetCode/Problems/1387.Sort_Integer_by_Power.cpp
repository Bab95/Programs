class Solution {
public:
    int getsteps(int i){
        int count = 0;
        while(i!=1){
            if(i%2==0){
                i = i/2;
            }else{
                i = 3*i+1;
            }
            count++;
        }
        return count;
    }
    static bool compare(const pair<int,int>& p1,const pair<int,int>& p2){
        if(p1.second<p2.second){
            return true;
        }
        if(p1.second==p2.second){
            if(p1.first<p2.first){
                return true;
            }
        }
        return false;
    }
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int> > arr(hi-lo+1);
        for(int i=lo,j=0;i<=hi;++i,++j){
            arr[j].first = i;
            arr[j].second = getsteps(i);
        }
        /*for(int i=0;i<arr.size();++i){
            cout<<arr[i].first<<" "<<arr[i].second<<endl;
        }*/
        sort(arr.begin(),arr.end(),compare);
        return arr[k-1].first;
    }
};
