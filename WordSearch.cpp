class Solution {
	bool _Find(vector<vector<char> >& board, int curM, int curN, 
			string& word, int p, vector<vector<bool> >& used) {
		if (p >= word.size()) return true;
		
		int m = board.size();
		int n = board[0].size();
		static int M_DIFF[] = {-1, 0, 1, 0};
		static int N_DIFF[] = {0, 1, 0, -1};
		
		for (int i = 0; i < 4; ++i) {
			int newM = curM + M_DIFF[i];
			int newN = curN + N_DIFF[i];
			if (newM < 0 || newM >= m || newN < 0 || newN >= n)
				continue;
			if (used[newM][newN])
				continue;
			if (board[newM][newN] == word[p]) {
				used[newM][newN] = true;
				if (_Find(board, newM, newN, word, p+1, used))
					return true;
				else
					used[newM][newN] = false;
			}
		}
		return false;
	}
	
public:
    bool exist(vector<vector<char> > &board, string word) {
        if (board.empty() || board[0].empty() || word.empty())
			return false;
		
		int m = board.size();
		int n = board[0].size();
		
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (board[i][j] == word[0]) {
					vector<vector<bool> > used(m, vector<bool>(n, false));
					used[i][j] = true;
					if (_Find(board, i, j, word, 1, used)) return true;
					used[i][j] = false;
				}
			}
		}
		return false;
    }
};