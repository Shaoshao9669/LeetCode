#ifndef _TRAPPING_RAIN_WATER_2_H_
#define _TRAPPING_RAIN_WATER_2_H_

/*
Given an m x n integer matrix heightMap representing the height of each unit cell in a 2D elevation map, return the volume of water it can trap after raining.

Example 1:
Input: heightMap = [[1, 4, 3, 1, 3, 2], [3, 2, 1, 3, 2, 4], [2, 3, 3, 2, 3, 1]]
Output : 4
Explanation : After the rain, water is trapped between the blocks.
We have two small ponds 1 and 3 units trapped.
The total volume of water trapped is 4.

Example 2 :
Input : heightMap = [[3, 3, 3, 3, 3], [3, 2, 2, 2, 3], [3, 2, 1, 2, 3], [3, 2, 2, 2, 3], [3, 3, 3, 3, 3]]
Output : 10
*/

#include "common.h"

namespace TrappingRainWater2
{
	class Solution
	{
	public:
		static int trapRainWater(vector<vector<int>>& heightMap)
		{
			priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;

			int m = heightMap.size();
			int n = heightMap[0].size();
			int max_height = -1;
			int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
			int ret = 0;

			vector<vector<bool>> visited(m, vector<bool>(n, false));

			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (i == 0 || j == 0 || i == m - 1 || j == n - 1)
					{
						queue.push({ heightMap[i][j], i * n + j });
						visited[i][j] = true;
					}
				}
			}
			while (queue.empty() == false)
			{
				pair<int, int> queue_pair = queue.top();
				queue.pop();

				int height = queue_pair.first;
				int row = queue_pair.second / n;
				int col = queue_pair.second % n;
				max_height = max(height, max_height);

				for (int i = 0; i < 4; i++)
				{
					int x = row + dir[i][0];
					int y = col + dir[i][1];

					if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y])
					{
						continue;
					}
					visited[x][y] = true;
					if (heightMap[x][y] < max_height)
					{
						ret += (max_height - heightMap[x][y]);
					}
					queue.push({ heightMap[x][y], x * n + y });
				}
			}

			return ret;
		}

		static void test()
		{
			vector<vector<int>> heightMap1 = { {1, 4, 3, 1, 3, 2}, {3, 2, 1, 3, 2, 4}, {2, 3, 3, 2, 3, 1} };
			vector<vector<int>> heightMap2 = { {3, 3, 3, 3, 3}, {3, 2, 2, 2, 3}, {3, 2, 1, 2, 3}, {3, 2, 2, 2, 3}, {3, 3, 3, 3, 3} };

			int output1 = trapRainWater(heightMap1);
			int output2 = trapRainWater(heightMap2);

			OutputSingleNumber(output1);
			OutputSingleNumber(output2);
		}
	};
}

#endif // _TRAPPING_RAIN_WATER_2_H_
