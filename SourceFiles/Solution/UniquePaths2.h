#ifndef _UNIQUE_PATH_2_H_
#define _UNIQUE_PATH_2_H_

/*
LeetCode 63:
You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.
Return the number of possible unique paths that the robot can take to reach the bottom-right corner.
The testcases are generated so that the answer will be less than or equal to 2 * 109.

Example 1:
Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

Example 2:
Input: obstacleGrid = [[0,1],[0,0]]
Output: 1
*/

#include "common.h"

namespace UniquePaths2
{
	class Solution
	{
	public:
		static int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
		{
			int m = obstacleGrid.size();
			int n = obstacleGrid[0].size();

			if (obstacleGrid[0][0] == 1)
			{
				return 0;
			}

			vector<vector<int>> sum_path(m);
			for (int i = 0; i < m; i++)
			{
				sum_path[i].resize(n);
			}

			sum_path[0][0] = 1;
			for (int i = 1; i < m; i++)
			{
				if (obstacleGrid[i][0] == 1)
				{
					sum_path[i][0] = 0;
				}
				else
				{
					sum_path[i][0] = sum_path[i - 1][0];
				}		
			}

			for (int i = 1; i < n; i++)
			{
				if (obstacleGrid[0][i] == 1)
				{
					sum_path[0][i] = 0;
				}
				else
				{
					sum_path[0][i] = sum_path[0][i - 1];
				}
			}

			for (int i = 1; i < m; i++)
			{
				for (int j = 1; j < n; j++)
				{
					if (obstacleGrid[i][j] == 1)
					{
						sum_path[i][j] = 0;
					}
					else
					{
						sum_path[i][j] = sum_path[i][j - 1] + sum_path[i - 1][j];
					}
				}
			}

			return sum_path[m - 1][n - 1];
		}

		static void test()
		{
			vector<vector<int>> obstacleGrid1 = { {0, 0, 0}, {0, 1, 0}, {0, 0, 0} };
			vector<vector<int>> obstacleGrid2 = { {0, 1}, {0, 0} };

			int output1 = uniquePathsWithObstacles(obstacleGrid1);
			int output2 = uniquePathsWithObstacles(obstacleGrid2);

			OutputSingleNumber(output1);
			OutputSingleNumber(output2);
		}
	};
}

#endif // _UNIQUE_PATH_2_H_
