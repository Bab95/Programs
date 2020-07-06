class Solution {
public:
    bool isPathCrossing(string path) {
        pair<int,int> current_position;
        current_position.first = 0;
        current_position.second = 0;
        set<pair<int,int> > visited;
        visited.insert(current_position);
        for(int i=0;i<path.size();++i){
            switch(path[i]){
                case 'N':
                    current_position.second += 1;
                    if(visited.count(current_position)!=0){
                        return true;
                    }
                    visited.insert(current_position);
                    break;
                case 'E':
                    current_position.first+=1;
                    if(visited.count(current_position)!=0){
                        return true;
                    }
                    visited.insert(current_position);
                    break;
                case 'S':
                    current_position.second -= 1;
                    if(visited.count(current_position)!=0){
                        return true;
                    }
                    visited.insert(current_position);
                    break;
                case 'W':
                    current_position.first -= 1;
                    if(visited.count(current_position)!=0){
                        return true;
                    }
                    visited.insert(current_position);
                    break;
                default:
                    break;
            }
        }
        return false;
    }
};
