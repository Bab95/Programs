class Solution {
public:
    bool canConstruct(string ransomNote, string magzine) {
        unordered_map<char,int> mag;
        for(int i=0;i<magzine.length();++i){
            mag[magzine[i]]+=1;
        }
        unordered_map<char,int> rmap;
        for(int i=0;i<ransomNote.length();++i){
            rmap[ransomNote[i]]+=1;
        }
        for(auto it=rmap.begin();it!=rmap.end();++it){
            if(mag.find(it->first)==mag.end()){
                return false;
            }else if(mag[it->first]<it->second){
                return false;
            }
        }
        return true;
    }
};
