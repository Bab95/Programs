class Solution {
public:
    bool canTransform(string start, string end) {
        vector<pair<char,int> > start_,end_;
        vector<int> a(3,0),b(3,0);
        int n = start.length();
        for(int i=0;i<n;++i){
            if(start[i]=='X'){
                a[0]++;
            }else if(start[i]=='L'){
                a[1]++;
                start_.push_back(make_pair(start[i],i));
            }
            else if(start[i]=='R'){
                a[2]++;
                start_.push_back(make_pair(start[i],i));
            }
        }

        for(int i=0;i<n;++i){
            if(end[i]=='X'){
                b[0]++;
            }else if(end[i]=='L'){
                b[1]++;
                end_.push_back(make_pair(end[i],i));
            }else if(end[i]=='R'){
                b[2]++;
                end_.push_back(make_pair(end[i],i));
            }
        }

        if(a[0]!=b[0]||a[1]!=b[1]||a[2]!=b[2]){
            //cout<<"e1"<<endl;
            return false;
        }

        for(int i=0;i<start_.size();++i){
            if(start_[i].first!=end_[i].first){
                //cout<<"e2"<<endl;
                return false;
            }else if(start_[i].first==end_[i].first){
                if(start_[i].first=='L'){
                    if(start_[i].second<end_[i].second){
                        //cout<<"e3"<<endl;
                        return false;
                    }
                }else if(start_[i].first=='R'){
                    if(start_[i].second>end_[i].second){
                        //cout<<"e4"<<endl;
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
