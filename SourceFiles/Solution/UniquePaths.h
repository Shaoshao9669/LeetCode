#ifndef _UNIQUE_PATH_H_
#define _UNIQUE_PATH_H_

/*
LeetCode 62:
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.
The test cases are generated so that the answer will be less than or equal to 2 * 109.

Example 1:
Input: m = 3, n = 7
Output: 28

Example 2:
Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
*/

#include "common.h"

namespace UniquePaths
{
	class Solution 
	{
	public:
		static int uniquePaths(int m, int n)
		{
			vector<vector<int>> sum_path(m);
			for (int i = 0; i < m; i++)
			{
				sum_path[i].resize(n);
			}

			sum_path[0][0] = 1;
			for (int i = 1; i < m; i++)
			{
				sum_path[i][0] = sum_path[i - 1][0];
			}

			for (int i = 1; i < n; i++)
			{
				sum_path[0][i] = sum_path[0][i - 1];
			}

			for (int i = 1; i < m; i++)
			{
				for (int j = 1; j < n; j++)
				{
					sum_path[i][j] = sum_path[i][j - 1] + sum_path[i - 1][j];
				}
			}

			return sum_path[m - 1][n - 1];
		}

		static void test()
		{
			int m_1 = 3, n_1 = 7;
			int m_2 = 3, n_2 = 2;

			int output1 = uniquePaths(m_1, n_1);
			int output2 = uniquePaths(m_2, n_2);

			OutputSingleNumber(output1);
			OutputSingleNumber(output2);
		}
	};
}

#endif // _UNIQUE_PATH_H_
