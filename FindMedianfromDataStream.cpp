class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> minheap;
    priority_queue<int, vector<int>, less<int>> maxheap;
    // Adds a number into the data structure.
    void addNum(int num) {
        if (minheap.empty() && maxheap.empty()) { maxheap.push(num); return ;}
        if (maxheap.size() > minheap.size()) 
            minheap.push(num);
        else maxheap.push(num);
        
        if (maxheap.top() > minheap.top()) {
            int tmp1 = maxheap.top();
            int tmp2 = minheap.top();
            maxheap.pop();
            maxheap.push(tmp2);
            minheap.pop();
            minheap.push(tmp1);
        }
        
    }

    // Returns the median of current data stream
    double findMedian() {
        if (maxheap.size() > minheap.size()) return maxheap.top();
        else return (maxheap.top() + minheap.top()) / 2.0;
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();