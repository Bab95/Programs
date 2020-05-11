class Solution {
public:
    bool func(vector<int>& p1,vector<int>& p2,double m){
        double x = (double)p2[0];
        double y = (double)p2[1];
        double x1 = (double)p1[0];
        double y1 = (double)p1[1];
        //cout<<x<< " "<<y<<" "<<x1<<" "<<y1<<endl;
        double tmp = m*(x-x1) + y1;
        //cout<<tmp<<" "<<y<<endl;
        if(tmp-y==0){
           //cout<<"here"<<endl;
            return true;
        }
        return false;
    }
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int y2 = coordinates[1][1];
        int y1 = coordinates[0][1];
        int x2 = coordinates[1][0];
        int x1 = coordinates[0][0];
        int num = y2-y1;
        int denom = x2-x1;
        if(denom!=0){
            double m = (double)num/denom*(1.0);
            //cout<<m<<endl;
            for(int i=2;i<coordinates.size();++i){
                if(!func(coordinates[0],coordinates[i],m)){
                    //cout<<"i: "<<i<<endl;
                    return false;
                }
            }
        }else{
            for(int i=1;i<coordinates.size();++i){
                if(coordinates[i][0]!=coordinates[0][0]){
                    return false;
                }
            }
        }
        return true;
    }
};
