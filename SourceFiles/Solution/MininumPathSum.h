#ifndef _MININUM_PATH_SUM_H_
#define _MININUM_PATH_SUM_H_

/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.

Example 1:
Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 ¡ú 3 ¡ú 1 ¡ú 1 ¡ú 1 minimizes the sum.

Example 2:
Input: grid = [[1,2,3],[4,5,6]]
Output: 12
*/

#include "common.h"

namespace MininumPathSum
{
	class Solution
	{
	public:
		static int minPathSum(vector<vector<int>>& grid)
		{
			int m = grid.size();
			int n = grid[0].size();
			int sum = 0;
			vector<vector<int>> path_sum(m, vector<int>(n));

			path_sum[0][0] = grid[0][0];

			for (int i = 1; i < m; i++)
			{
				path_sum[i][0] = path_sum[i - 1][0] + grid[i][0];
			}
			for (int i = 1; i < n; i++)
			{
				path_sum[0][i] = path_sum[0][i - 1] + grid[0][i];
			}

			for (int i = 1; i < m; i++)
			{
				for (int j = 1; j < n; j++)
				{
					path_sum[i][j] = min(path_sum[i - 1][j], path_sum[i][j - 1]) + grid[i][j];
				}
			}

			return path_sum[m - 1][n - 1];
		}

		static void test()
		{
			vector<vector<int>> grid1 = { { 1, 3, 1 }, { 1, 5, 1 }, { 4, 2, 1 }};
			vector<vector<int>> grid2 = { { 1, 2, 3 }, { 4, 5, 6 }};

			int num1 = minPathSum(grid1);
			int num2 = minPathSum(grid2);

			OutputSingleNumber(num1);
			OutputSingleNumber(num2);
		}
	};
}

#endif // _MININUM_PATH_SUM_H_
