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
    vector<Interval> merge(vector<Interval> &intervals) {
		if (intervals.empty()) return vector<Interval>();
		
        sort(intervals.begin(), intervals.end(),
			[](const Interval& v1, const Interval& v2) {
			return v1.start < v2.start;});
		
		size_t last = 0;
		for (size_t pos = 1; pos < intervals.size(); ++pos) {
			if (intervals[pos].start > intervals[pos].end) {
				intervals[last++] = intervals[pos];
			} else {
				intervals[last].end = max(intervals.end, intervals[pos].last);
			}
		}
		
		return vector<Interval>(intervals.begin(), intervals.begin() + last);
    }
};