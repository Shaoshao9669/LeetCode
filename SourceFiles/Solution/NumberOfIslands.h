#ifndef _NUMBER_OF_ISLANDS_H_
#define _NUMBER_OF_ISLANDS_H_

/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Example 2:
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
*/

#include "common.h"

namespace NumberOfIslands
{
	class Solution
	{
	public:
		static queue<pair<int, int>> grid_queue;

		static void del_pair(pair<int, int> p)
		{
			queue<pair<int, int>> push_queue;

			while (grid_queue.empty() == false)
			{ 
				if (p != grid_queue.front())
				{
					push_queue.push(grid_queue.front());
				}
				grid_queue.pop();
			}

			swap(grid_queue, push_queue);
		}

		static void dfs(vector<vector<char>>& grid, int x, int y)
		{
			int m = grid.size();
			int n = grid[0].size();

			if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == '0')
			{
				return;
			}

			grid[x][y] = '0';
			del_pair({x, y});

			dfs(grid, x + 1, y);
			dfs(grid, x - 1, y);
			dfs(grid, x, y + 1);
			dfs(grid, x, y - 1);
		}

		static int numIslands(vector<vector<char>>& grid)
		{
			int m = grid.size();
			int n = grid[0].size();

			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if ('1' == grid[i][j])
					{
						grid_queue.push({ i, j });
					}
				}
			}

			int cluster_num = 0;
			while (grid_queue.empty() == false)
			{
				int x = grid_queue.front().first;
				int y = grid_queue.front().second;

				dfs(grid, x, y);

				cluster_num++;
			}

			return cluster_num;
		}

		static void test()
		{
			vector<vector<char>> grid1 = { {'1', '1', '1', '1', '0'},  {'1', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0'} };
			vector<vector<char>> grid2 = { {'1', '1', '0', '0', '0'},  {'1', '1', '0', '0', '0'}, {'0', '0', '1', '0', '0'}, {'0', '0', '0', '1', '1'} };

			int num1 = numIslands(grid1);
			int num2 = numIslands(grid2);

			OutputSingleNumber(num1);
			OutputSingleNumber(num2);
		}
	};

	queue<pair<int, int>> Solution::grid_queue;
}

#endif // _NUMBER_OF_ISLANDS_H_
