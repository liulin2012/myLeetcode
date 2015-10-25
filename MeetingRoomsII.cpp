/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), compare);
        int res = 1;
        priority_queue<int, vector<int>, greater<int>> heap;
        heap.push(intervals[0].end);
        for (int i = 1; i < intervals.size(); i++) {
            while (!heap.empty() && intervals[i].start >= heap.top())
                heap.pop();
            heap.push(intervals[i].end);
            res = max(res, (int)heap.size());
        }
        return res;
    }
    
    static bool compare(Interval& interval1, Interval& interval2) {
        return interval1.start < interval2.start;
    }    
    
};