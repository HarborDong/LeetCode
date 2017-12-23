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
    static bool comp(const struct Interval &a, const struct Interval &b) {
        return a.start < b.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ret;
        int index = 0, next = 0;
        int start = 0, end = 0;
        if(intervals.size() < 2) return intervals;
        sort(intervals.begin(), intervals.end(), comp);
        while(index < intervals.size()) {
            start = intervals[index].start;
            end = intervals[index].end;
            next = index + 1;
            while(next < intervals.size()) {
                if(intervals[next].start <= end) {
                    
                    end = end > intervals[next].end ? end : intervals[next].end; 
                    next++;
                } else {
                    index = next;
                    break;
                }
            }
            if(next == intervals.size()) {
                index = next;
            }
            struct Interval item(start, end);
            ret.push_back(item);
        }
        return ret;
    }
};
