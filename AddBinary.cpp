
class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
		int i = a.length() - 1;
		int j = b.length() - 1;
		string strRet;
		while (i >= 0 || j >= 0 || carry) {
			int m = 0;
			if (i >= 0) {
				m = a[i--] - '0';
			}
			
			int n = 0;
			if (j >= 0) {
				n = b[j--] - '0';
			}
			
			int s = m + n + carry;
			carry = s / 2;
			s = s % 2;
			strRet.append(s ? "1" : "0");
		}
		
		reverse(strRet.begin(), strRet.end());
		return strRet;			
    }
};
