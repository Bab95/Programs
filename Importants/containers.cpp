// Hash function for unordered_map of pair....

struct _hash_map{
  size_t operator () (const pair<int,int>& p){
    return p.first^p.second;
  }
};

//Hash function for unordered_set of pair...

struct _hash_set{
  template <class T1, class T2>
  size_t operator () (const pair<T1,T2>& p){
    size_t h1 = hash<T1>(p.first);
    size_t h2 = hash<T2>(p.second);
    return h1^h2;
  }
};
Both are same...
2nd hash is generalized.
