#ifndef _UNIQUE_PATH_3_H_
#define _UNIQUE_PATH_3_H_

/*
LeetCode 980:
You are given an m x n integer array grid where grid[i][j] could be:
1 representing the starting square. There is exactly one starting square.
2 representing the ending square. There is exactly one ending square.
0 representing empty squares we can walk over.
-1 representing obstacles that we cannot walk over.
Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

Example 1:
Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
Output: 2
Explanation: We have the following two paths:
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)

Example 2:
Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
Output: 4
Explanation: We have the following four paths:
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)

Example 3:
Input: grid = [[0,1],[2,0]]
Output: 0
Explanation: There is no path that walks over every empty square exactly once.
Note that the starting and ending square can be anywhere in the grid.
*/

#include "common.h"

namespace UniquePaths3
{
	class Solution
	{
	public:
		static int sum_path;
		static vector<pair<int, int>> path;
		static vector<vector<pair<int, int>>> sum_path_vec;

		static void dfs(vector<vector<int>> &grid, int current_step, int x, int y, pair<int, int> end, int sum_step)
		{
			int m = grid.size();
			int n = grid[0].size();

			if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == -1)
			{
				return;
			}
			if (current_step == sum_step && (x == end.first && y == end.second))
			{
				path.push_back({ x, y });
				sum_path_vec.push_back(path);
				sum_path++;
				return;
			}

			grid[x][y] = -1;
			current_step = current_step + 1;
			path.push_back({ x, y });
			dfs(grid, current_step, x + 1, y, end, sum_step);
			dfs(grid, current_step, x - 1, y, end, sum_step);
			dfs(grid, current_step, x, y + 1, end, sum_step);
			dfs(grid, current_step, x, y - 1, end, sum_step);
			path.pop_back();
			grid[x][y] = 0;
		}

		static int uniquePathsIII(vector<vector<int>>& grid)
		{
			sum_path = 0;
			int m = grid.size();
			int n = grid[0].size();
			pair<int, int> start, end;
			int sum_step = 0;

			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (grid[i][j] == 0)
					{
						sum_step++;
					}
					if (grid[i][j] == 1)
					{
						start = { i ,j };
					}
					if (grid[i][j] == 2)
					{
						end = { i, j };
					}
				}
			}

			int current_step = -1;
			int x = start.first; int y = start.second;

			dfs(grid, current_step, x, y, end, sum_step);

			return sum_path;
		}

		static void test()
		{
			vector<vector<int>> grid1 = { {1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 2, -1} };
			vector<vector<int>> grid2 = { {1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 2} };
			vector<vector<int>> grid3 = { {0, 1}, {2, 0} };

			int output1 = uniquePathsIII(grid1);
			int output2 = uniquePathsIII(grid2);
			int output3 = uniquePathsIII(grid3);

			OutputSingleNumber(output1);
			OutputSingleNumber(output2);
			OutputSingleNumber(output3);
		}
	};

	int Solution::sum_path = 0;
	vector<pair<int, int>> Solution::path;
	vector<vector<pair<int, int>>> Solution::sum_path_vec;
}
#endif // _UNIQUE_PATH_3_H_
