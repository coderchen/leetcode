class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows == 1) return s;
		vector<string> line(nRows);
		int i = 0;
		while (i < s.size()) {
			for (int j = 0; j < nRows && i < s.size(); ++j) {
				line[j] += s[i++];
			}
			
			for (int j = nRows - 2; j > 0 && i < s.size(); --j) {
				line[j] += s[i++];
			}
		}
		
		string result;
		for (auto l : line)
			result += l;
		return result;
    }
};