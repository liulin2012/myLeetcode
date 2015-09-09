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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        bool ist = false;
        if (intervals.size() != 0 && newInterval.end < intervals[0].start) res.push_back(newInterval);
        for (int i = 0; i < intervals.size(); i++) {
            if (newInterval.start > intervals[i].end || newInterval.end < intervals[i].start) {
                if (i != 0 && newInterval.end < intervals[i].start && newInterval.start > intervals[i - 1].end) res.push_back(newInterval);
                else if (ist) {res.push_back(newInterval); ist = false;}
                res.push_back(intervals[i]);
            } else {
                if (!ist) newInterval.start = min(newInterval.start, intervals[i].start); 
                newInterval.end = max(newInterval.end, intervals[i].end); 
                ist = true;
            }
        }
        if (ist || intervals.size() == 0 || newInterval.start > intervals[intervals.size() - 1].end) res.push_back(newInterval);
        
        return res;
    }
};