#include <iostream>

/*
 * 计算N个结点可以组成多少个二叉搜索树
 * 对于每一个N, 可以得知根节点的左子树结点个数为L_CNT[0, N-1), 右子树结点个数为[N-1, 0）
 * 分别计算出没中情况下可以组成多少个二叉搜索树
 */

//非递归求解
class Solution {
public:
	int numTrees(int n) {
		if (n == 0 || n == 1) return 1;

		int* cnt = new int[n + 1];
		cnt[0] = 1;
		cnt[1] = 1;

		for (int i = 2; i <= n; ++i)
		{
			int subTreeCnt = 0;
			for (int j = 0; j < i; ++j)
			{
				int lSubTreeCnt = cnt[j];
				int rSubTreeCnt = cnt[i - 1 - j];
				subTreeCnt += lSubTreeCnt * rSubTreeCnt;
			}
			cnt[i] = subTreeCnt;
		}

		int ret = cnt[n];
		delete []cnt;
		return ret;
	}
};

//递归求解
class Solution_2 {
public:
	int numTrees(int n) {
		if (n == 0 || n == 1) return 1;

		int cnt = 0;
		for (int i = 0; i < n; ++i)
		{
			cnt += numTrees(i) * numTrees(n - 1 - i);
		}
		return cnt;
	}
};

int main()
{
	Solution s;
	for (int i = 0; i < 10; ++i)
	{
		std::cout << i << " " << s.numTrees(i) << std::endl;
	}

	Solution_2 s2;
	for (int i = 0; i < 10; ++i)
	{
		std::cout << i << " " << s2.numTrees(i) << std::endl;
	}
	return 0;
}