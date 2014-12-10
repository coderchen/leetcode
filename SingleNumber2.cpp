class Solution {
public:
    int singleNumber(int A[], int n) {
        int bitCnt[32] = {0};
        for (int i = 0; i < 32; ++i)
        {
            int flag = (1 << i);
            for (int j = 0; j < n; ++j)
                bitCnt[i] += (A[j] & flag) ? 1 : 0;
        }
        int result = 0;
        for (int i = 0; i < 32; ++i)
            result |= (bitCnt[i] % 3) ? (1 << i) : 0;
        return result;
    }
};