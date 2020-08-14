class CombinationIterator {
public:
    vector<string> ss;
    int pointer,total;
    void generate(string current,int current_index,string& characters,int combinationLength,int& index){

        if(current.length()==combinationLength){
            ss[index] = current;
            index++;
            return;
        }
        for(int i=current_index;i<characters.length();++i){
            current.push_back(characters[i]);
            generate(current,i+1,characters,combinationLength,index);
            current.pop_back();
        }
    }
    int nCr(int n,int r){
        int ans = 1;
        for(int i=0;i<r;++i){
            ans *= (n-i);
        }
        for(int i=1;i<=r;++i){
            ans /= i;
        }
        return ans;
    }
    CombinationIterator(string characters, int combinationLength) {
        int n = characters.length();
        total = nCr(n,combinationLength);
        ss.clear();
        ss.resize(total);
        string current = "";
        int index = 0;
        generate(current,0,characters,combinationLength,index);
        pointer = 0;

    }

    string next() {
        int current = pointer;
        pointer++;
        return ss[current];
    }

    bool hasNext() {
        if(pointer==total){
            return false;
        }
        return true;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
