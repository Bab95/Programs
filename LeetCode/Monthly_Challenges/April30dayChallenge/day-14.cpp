class Solution {
public:
    void swap(char *a,char *b){
        char tmp = *a;
        *a = *b;
        *b = tmp;
    }
    void right_shift(string& s,int net_shift){
        int l = 0;
        int r = s.length()-1;
        while(l<r){
            swap(&s[l],&s[r]);
            ++l;
            --r;
        }
        l = 0;
        r = net_shift-1;
        while(l<r){
            swap(&s[l],&s[r]);
            ++l;
            --r;
        }
        l = net_shift;
        r = s.length()-1;
        while(l<r){
            swap(&s[l],&s[r]);
            ++l;
            --r;
        }
    }
    void left_shift(string& s,int net_shift){
        int l = 0;
        int r = s.length()-1;
        while(l<r){
            swap(&s[l],&s[r]);
            ++l;
            --r;
        }
        l = 0;
        r = s.length()-net_shift-1;
        while(l<r){
            swap(&s[l],&s[r]);
            ++l;
            --r;
        }
        l = s.length()-net_shift;
        r = s.length()-1;
        while(l<r){
            swap(&s[l],&s[r]);
            ++l;--r;
        }
    }
    string stringShift(string s, vector<vector<int>>& shift) {
        int net_shift = 0;
        for(int i=0;i<shift.size();++i){
            if(shift[i][0]==0){
                net_shift-=shift[i][1];
            }else{
                net_shift+=shift[i][1];
            }
        }
        cout<<net_shift<<endl;
        if(net_shift<0){
            net_shift = -1*net_shift;
            net_shift = net_shift%s.length();
            left_shift(s,net_shift);
        }else{
            net_shift = net_shift%s.length();
            right_shift(s,net_shift);
        }
        return s;
    }
};
