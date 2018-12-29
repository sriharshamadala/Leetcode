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
        vector<Interval> result;
        
        if (intervals.size() == 0) return result;
        
        sort(intervals.begin(), intervals.end(), [](Interval i1, Interval i2) -> bool {return i1.start < i2.start;});
        
        Interval temp_interval(intervals[0].start, intervals[0].end);
        for (int ii = 0; ii < intervals.size() - 1; ++ii) {
            if (intervals[ii + 1].start <= temp_interval.end) {
                // Overlap
                temp_interval.end = max(intervals[ii + 1].end, temp_interval.end);
            } else {
                result.push_back(temp_interval);
                temp_interval.start = intervals[ii + 1].start;
                temp_interval.end = intervals[ii + 1].end;
            }
        }
        result.push_back(temp_interval);
        return result;
    }
    
};