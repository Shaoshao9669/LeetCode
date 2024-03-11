#ifndef _ROTTING_ORANGES_H_
#define _ROTTING_ORANGES_H_

/*
You are given an m x n grid where each cell can have one of three values :

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4 - directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.If this is impossible, return -1.

Example 1:
Input: grid = [[2, 1, 1], [1, 1, 0], [0, 1, 1]]
Output : 4

Example 2 :
Input : grid = [[2, 1, 1], [0, 1, 1], [1, 0, 1]]
Output : -1
Explanation : The orange in the bottom left corner(row 2, column 0) is never rotten, because rotting only happens 4 - directionally.

Example 3 :
Input : grid = [[0, 2]]
Output : 0
Explanation : Since there are already no fresh oranges at minute 0, the answer is just 0.
*/

#include "common.h"

namespace RottingOranges
{
	class Solution
	{
	public:
		static queue<pair<int, int>> rotting_queue;
		static int fresh;

		static void bfs(vector<vector<int>>& grid, int x, int y)
		{
			int m = grid.size();
			int n = grid[0].size();

			if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == 0 || grid[x][y] == 2)
			{
				return;
			}
			grid[x][y] = 2;
			fresh--;
			rotting_queue.push({ x, y });
		}

		static int orangesRotting(vector<vector<int>>& grid)
		{
			int m = grid.size();
			int n = grid[0].size();
			int minute = 0;
			fresh = 0;

			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (grid[i][j] == 2)
					{
						rotting_queue.push({ i, j });
					}
					else if (grid[i][j] == 1)
					{
						fresh++;
					}
				}
			}

			while (fresh > 0 && rotting_queue.empty() == false)
			{
				int size = rotting_queue.size();

				for (int i = 0; i < size; i++)
				{
					pair<int, int> rotting_grid = rotting_queue.front();
					rotting_queue.pop();

					bfs(grid, rotting_grid.first + 1, rotting_grid.second);
					bfs(grid, rotting_grid.first - 1, rotting_grid.second);
					bfs(grid, rotting_grid.first, rotting_grid.second + 1);
					bfs(grid, rotting_grid.first, rotting_grid.second - 1);
				}

				minute++;
			}

			return (fresh > 0) ? -1 : minute;
		}

		static void test()
		{
			vector<vector<int>> nums1 = { { 2, 1, 1 }, { 1, 1, 0 }, { 0, 1, 1 } };
			vector<vector<int>> nums2 = { { 2, 1, 1 }, { 0, 1, 1 }, { 1, 0, 1 } };
			vector<vector<int>> nums3 = { { 0, 2 } };

			int num1 = orangesRotting(nums1);
			int num2 = orangesRotting(nums2);
			int num3 = orangesRotting(nums3);

			OutputSingleNumber(num1);
			OutputSingleNumber(num2);
			OutputSingleNumber(num3);
		}
	};

	queue<pair<int, int>> Solution::rotting_queue;
	int Solution::fresh = 0;
}
#endif // _ROTTING_ORANGES_H_
