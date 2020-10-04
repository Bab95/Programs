class RecentCounter {
public:
    vector<int> calls;
    RecentCounter() {

    }
    int ping(int t) {
        calls.push_back(t);
        auto it = lower_bound(calls.begin(),calls.end(),t-3000);
        int n = calls.size();
        int prev = it-calls.begin();
        return n-prev;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
