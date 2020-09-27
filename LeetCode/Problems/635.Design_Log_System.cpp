class LogSystem {
public:
    map<string,int> mmap;
    unordered_map<string,int> _time;
    LogSystem() {
        _time["year"] = 4;
        _time["month"] = 7;
        _time["day"] = 10;
        _time["hour"] = 13;
        _time["minute"] = 16;
        _time["second"] = 19;
    }

    void put(int id, string timestamp) {
        mmap[timestamp] = id;
    }
    void to_lower(string& a){
        for(int i=0;i<a.length();++i){
            if(a[i]>='A'&&a[i]<='Z'){
                a[i] = a[i]-'A'+'a';
            }
        }
    }
    vector<int> retrieve(string s, string e, string gra) {
        to_lower(gra);
        vector<int> ans;
        s = s.substr(0,_time[gra]);
        e = e.substr(0,_time[gra]);
        for(auto it=mmap.begin();it!=mmap.end();it++){
            string current = it->first.substr(0,_time[gra]);
            if(current>=s&&current<=e){
                ans.push_back(it->second);
            }
        }
        return ans;
    }
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem* obj = new LogSystem();
 * obj->put(id,timestamp);
 * vector<int> param_2 = obj->retrieve(s,e,gra);
 */


 /*
 class LogSystem {
 public:
     map<string,int> mmap;
     LogSystem() {

     }

     void put(int id, string timestamp) {
         mmap[timestamp] = id;
     }
     void to_lower(string& a){
         for(int i=0;i<a.length();++i){
             if(a[i]>='A'&&a[i]<='Z'){
                 a[i] = a[i]-'A'+'a';
             }
         }
     }
     vector<int> retrieve(string s, string e, string gra) {
         to_lower(gra);
         vector<int> ans;
         for(auto it=mmap.begin();it!=mmap.end();++it){
             if(gra=="year"){
                 string current = it->first.substr(0,4);
                 if(current>=s.substr(0,4)&&current<=e.substr(0,4)){
                     ans.push_back(it->second);
                 }
             }else if(gra=="month"){
                 string current = it->first.substr(0,7);
                 if(current>=s.substr(0,7)&&current<=e.substr(0,7)){
                     ans.push_back(it->second);
                 }
             }else if(gra=="day"){
                 string current = it->first.substr(0,10);
                 if(current>=s.substr(0,10)&&current<=e.substr(0,10)){
                     ans.push_back(it->second);
                 }
             }else if(gra=="hour"){
                 string current = it->first.substr(0,13);
                 if(current>=s.substr(0,13)&&current<=e.substr(0,13)){
                     ans.push_back(it->second);
                 }
             }else if(gra=="minute"){
                 string current = it->first.substr(0,15);
                 if(current>=s.substr(0,15)&&current<=e.substr(0,15)){
                     ans.push_back(it->second);
                 }
             }else if(gra=="second"){
                 if(it->first>=s&&it->first<=e){
                     ans.push_back(it->second);
                 }
             }
         }
         return ans;
     }
 };

 /**
  * Your LogSystem object will be instantiated and called as such:
  * LogSystem* obj = new LogSystem();
  * obj->put(id,timestamp);
  * vector<int> param_2 = obj->retrieve(s,e,gra);
  */
