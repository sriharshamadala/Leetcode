class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, std::greater<int>> min_heap;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (max_heap.size() + min_heap.size() == 0) {
            max_heap.push(num);
            return;
        }
        if (max_heap.size() > min_heap.size()) {
            // Median in max_heap. so compare the new num to it.
            if (num >= max_heap.top()) {
                min_heap.push(num);
            } else {
                max_heap.push(num);
                // Need to balance now.
                int temp = max_heap.top();
                max_heap.pop();
                min_heap.push(temp);
            }
        } else {
            // min_heap size >= max_heap size.
            if (num <= min_heap.top()) {
                max_heap.push(num);
            } else {
                min_heap.push(num);
                // May or may not be imbalanced.
                if (min_heap.size() > max_heap.size() + 1) {
                    int temp = min_heap.top();
                    min_heap.pop();
                    max_heap.push(temp);
                }
            }
        }        
    }
    
    double findMedian() {
        if (max_heap.size() == min_heap.size()) {
            if (max_heap.size() == 0) {
                return 0.0;
            }
            return (max_heap.top() + min_heap.top()) / 2.0;
        } else if (max_heap.size() > min_heap.size()) {
            return max_heap.top();
        } else {
            return min_heap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */