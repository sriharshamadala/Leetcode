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
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        int result = 0;
        if (intervals.size() == 0) return result;
        auto comp = [](const Interval& i1, const Interval& i2) {return i1.start < i2.start;};
        sort(intervals.begin(), intervals.end(), comp);
        
        Interval prev = intervals[0];
        for (int ii = 1; ii < intervals.size(); ++ii) {
            if (intervals[ii].start < prev.end) {
                // Conflict
                result++;
                if (prev.end > intervals[ii].end) {
                    prev = intervals[ii];
                }
            } else {
                prev = intervals[ii];
            }
        }
        return result;
    }
};