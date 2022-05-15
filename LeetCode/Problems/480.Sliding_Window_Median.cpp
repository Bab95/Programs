template<typename T, class Container=std::vector<T>, class Compare=std::less<typename Container::value_type>>
class my_priority_queue : public priority_queue<T, Container, Compare> {
public:
    bool remove(const T& value) {
        auto it = find(this->c.begin(), this->c.end(), value);
        if (it != this->c.end()) {
            this->c.erase(it);
            make_heap(this->c.begin(), this->c.end(), this->comp);
            return true;
        }
        return false;
    }
};
vector<int> _nums;
class Solution {
public:
    struct compare_min_heap {

    bool operator()(const int& a, const int& b) {
        return _nums[a] < _nums[b];
    }
    };
    struct compare_max_heap {
        bool operator()(const int& a, const int& b) {
            return _nums[a] > _nums[b];
        }
    };
    void balance_heaps(my_priority_queue<int, vector<int>, compare_max_heap>& min_heap, my_priority_queue<int, vector<int>, compare_min_heap>& max_heap) {
        if (max_heap.size() > min_heap.size()) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
    }
    double get_median(int k, vector<int>& nums, my_priority_queue<int, vector<int>, compare_max_heap>& min_heap, my_priority_queue<int, vector<int>, compare_min_heap>& max_heap){
        if (k % 2 == 0) {
            return ((double)nums[min_heap.top()] + (double)nums[max_heap.top()]) / (double)2;
        }
        return (double)nums[min_heap.top()];
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        _nums = nums;
        my_priority_queue<int, vector<int>, compare_min_heap> max_heap;
        my_priority_queue<int, vector<int>, compare_max_heap> min_heap;
        vector<double> result;
        for (int i = 0; i < nums.size(); i++) {
            if (i >= k) {
                max_heap.remove(i - k);
                min_heap.remove(i - k);
            }
            // element enters the min heap..
            min_heap.push(i);
            // now gets the element which is actually minimum after addition...
            max_heap.push(min_heap.top());
            min_heap.pop();
            // because max heap will have first half and min heap will have second half
            balance_heaps(min_heap, max_heap);
            if (i >= k - 1) {
                result.push_back(get_median(k, nums, min_heap, max_heap));
            }
        }
        return result;
    }
};
