#define pb push_back
#define mk make_pair
class Solution {
public:
    string intToRoman(int num) {
        vector<pair<string,int> > mpair;
        mpair.pb(mk("I",1));
        mpair.pb(mk("IV",4));
        mpair.pb(mk("V",5));
        mpair.pb(mk("IX",9));
        mpair.pb(mk("X",10));
        mpair.pb(mk("XL",40));
        mpair.pb(mk("L",50));
        mpair.pb(mk("XC",90));
        mpair.pb(mk("C",100));
        mpair.pb(mk("CD",400));
        mpair.pb(mk("D",500));
        mpair.pb(mk("CM",900));
        mpair.pb(mk("M",1000));
        int i = mpair.size()-1;
        string ans;
        while(i>=0&&num>=0){
            if(num-mpair[i].second>=0){
                ans.append(mpair[i].first);
                num = num-mpair[i].second;
            }else{
                i--;
            }
        }
        return ans;
    }
};
