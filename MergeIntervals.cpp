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
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if (intervals.size() == 0) return res;
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {return a.start < b.start;});
        int start = intervals[0].start, end = intervals[0].end;
        for (int i = 1; i < intervals.size(); i++) {
            if (end < intervals[i].start) {
                res.push_back(Interval(start, end));
                start = intervals[i].start;
                end = intervals[i].end;
            } else {
                end = max(intervals[i].end, end);
            }
        }
        res.push_back(Interval(start, end));
        return res;
    }
};