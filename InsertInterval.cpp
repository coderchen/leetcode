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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        intervals.push_back(newInterval);
		sort(intervals.begin(), intervals.end(), 
			[](const Interval& v1, const Interval& v2) {
				return v1.start < v2.start; });
		
		vector<Interval>::iterator it = intervals.begin();
		vector<Interval> retVec(it, it + 1);
		++it;
		while (it != intervals.end()) {
			Interval& vRef = *retVec.rbegin();
			if ((*it).start > vRef.end) {
				retVec.push_back(*it);
			} else {
				vRef.end = max(vRef.end, (*it).end);
			}
			
			++it;
		}
		
		return retVec;
    }
};