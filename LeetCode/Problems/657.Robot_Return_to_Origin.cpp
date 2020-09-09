class Solution {
public:
    bool judgeCircle(string moves) {
        pair<int,int> current;
        //queue<pair<int,int> > q;
        //q.push({0,0});
        current.first = 0;
        current.second = 0;
        for(int i=0;i<moves.length();++i){
            switch(moves[i]){
                case 'U':
                    current.first = current.first + 1;
                    break;
                case 'D':
                    current.first = current.first - 1;
                    break;
                case 'L':
                    current.second = current.second + 1;
                    break;
                case 'R':
                    current.second = current.second - 1;
                    break;
                default:
                    break;
            }
        }
        if(current.first==0&&current.second==0){
            return true;
        }
        return false;
    }
};
