class MedianFinder {
public:
    /** initialize your data structure here. */
    double med_ian;
    int num_elements;
    priority_queue<int> max_heap;
    priority_queue<int,vector<int>,greater<int> > min_heap;
    int min_heap_elements = 0;
    int max_heap_elements = 0;
    MedianFinder() {
        num_elements = 0;
        med_ian = 0;
    }
    void addNum(int num) {
        if(num_elements==0){
            max_heap.push(num);
        }else if(num_elements%2==0){
            if(num<min_heap.top()){
                max_heap.push(num);
            }else{
                int tmp = min_heap.top();
                min_heap.pop();
                max_heap.push(tmp);
                min_heap.push(num);
            }
        }else{
            if(num>max_heap.top()){
                min_heap.push(num);
            }else{
                int tmp = max_heap.top();
                max_heap.pop();
                max_heap.push(num);
                min_heap.push(tmp);
            }
        }
        num_elements++;
    }

    double findMedian() {
        if(num_elements%2==1){
            med_ian = (double)max_heap.top();
        }else if(num_elements%2==0){
            double m1 = (double)max_heap.top();
            double m2 = (double)min_heap.top();
            med_ian = (m1+m2)/2.0;
        }
        return med_ian;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
