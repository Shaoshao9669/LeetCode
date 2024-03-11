#ifndef _MAXIMUM_NUMBER_OF_POINTS_FROM_GRID_QUERIES_
#define _MAXIMUM_NUMBER_OF_POINTS_FROM_GRID_QUERIES_

/*
You are given an m x n integer matrix grid and an array queries of size k.
Find an array answer of size k such that for each integer queries[i] you start in the top left cell of the matrix and repeat the following process :
If queries[i] is strictly greater than the value of the current cell that you are in, then you get one point if it is your first time visiting this cell, and you can move to any adjacent cell in all 4 directions : up, down, left, and right.
Otherwise, you do not get any points, and you end this process.
After the process, answer[i] is the maximum number of points you can get.Note that for each query you are allowed to visit the same cell multiple times.
Return the resulting array answer.

Example 1:
Input: grid = [[1, 2, 3], [2, 5, 7], [3, 5, 1]], queries = [5, 6, 2]
Output : [5, 8, 1]
Explanation : The diagrams above show which cells we visit to get points for each query.

Example 2 :
Input : grid = [[5, 2, 1], [1, 1, 2]], queries = [3]
Output : [0]
Explanation : We can not get any points because the value of the top left cell is already greater than or equal to 3.
*/

#include "common.h"

namespace MaximumNumberOfPointsFromGridQueries
{
	class Solution
	{
	public:
		static int dfs(vector<vector<int>>& grid, int x, int y, int query)
		{
			int m = grid.size();
			int n = grid[0].size();

			if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] >= query)
			{
				return 0;
			}

			grid[x][y] = 10000;
			return (1 + dfs(grid, x + 1, y, query) + dfs(grid, x - 1, y, query) + dfs(grid, x, y + 1, query) + dfs(grid, x, y - 1, query));
		}

		static int maxPoint(vector<vector<int>>& grid, int query)
		{
			vector<vector<int>> temp = grid;

			return dfs(temp, 0, 0, query);
		}

		static vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries)
		{
			vector<int> res;

			for (int i = 0; i < (int)queries.size(); i++)
			{
				res.push_back(maxPoint(grid, queries[i]));
			}

			return res;
		}

		static void test()
		{
			vector<vector<int>> grid1 = { { 1, 2, 3 }, { 2, 5, 7 }, { 3, 5, 1 } };
			vector<vector<int>> grid2 = { { 5, 2, 1 }, { 1, 1, 2 } };

			vector<int> queries1 = { 5, 6, 2 };
			vector<int> queries2 = { 3 };

			vector<int> output1, output2;

			output1 = maxPoints(grid1, queries1);
			output2 = maxPoints(grid2, queries2);

			OutputVector(output1);
			OutputVector(output2);
		}
	};
}

#endif // _MAXIMUM_NUMBER_OF_POINTS_FROM_GRID_QUERIES_
