#ifndef _MAX_AREA_OF_ISLAND_H_
#define _MAX_AREA_OF_ISLAND_H_

/*
You are given an m x n binary matrix grid.An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
The area of an island is the number of cells with a value 1 in the island.
Return the maximum area of an island in grid.If there is no island, return 0.

Example 1:
Input: grid = [[0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0], [0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0], [0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0], [0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0], [0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0]]
Output : 6
Explanation : The answer is not 11, because the island must be connected 4 - directionally.

Example 2 :
Input : grid = [[0, 0, 0, 0, 0, 0, 0, 0]]
Output : 0
*/

#include "common.h"

namespace MaxAreaOfIsland
{
	class Solution
	{
	public:
		static int dfs(vector<vector<int>>& grid, int x, int y)
		{
			int m = grid.size();
			int n = grid[0].size();

			if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == 0)
			{
				return 0;
			}

			grid[x][y] = 0;

			return 1 + dfs(grid, x + 1, y) + dfs(grid, x - 1, y) + dfs(grid, x, y + 1) + dfs(grid, x, y - 1);
		}

		static int maxAreaOfIsland(vector<vector<int>>& grid)
		{
			int m = grid.size();
			int n = grid[0].size();
			int max = 0;

			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (grid[i][j] == 1)
					{
						int area = dfs(grid, i, j);
						if (max < area)
						{
							max = area;
						}
					}
				}
			}

			return max;
		}

		static void test()
		{
			vector<vector<int>> island1 = { {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0}, {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0} };
			vector<vector<int>> island2 = { {0, 0, 0, 0, 0, 0, 0, 0} };

			int num1 = maxAreaOfIsland(island1);
			int num2 = maxAreaOfIsland(island2);

			OutputSingleNumber(num1);
			OutputSingleNumber(num2);
		}
	};
}

#endif // _MAX_AREA_OF_ISLAND_H_
