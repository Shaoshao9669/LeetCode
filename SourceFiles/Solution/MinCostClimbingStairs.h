#ifndef _MIN_COST_CLIMBING_STAIRS_H_
#define _MIN_COST_CLIMBING_STAIRS_H_

/*
LeetCode746:
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.
You can either start from the step with index 0, or the step with index 1.
Return the minimum cost to reach the top of the floor.

Example 1:
Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.

Example 2:
Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.
*/

#include "common.h"

namespace MinCostClimbingStairs
{
	class Solution
	{
	public:
		static int MinCostClimbingStairs(vector<int>& cost)
		{
			int n = cost.size();

			vector<int> cost_sum(n);

			cost_sum[0] = 0;
			cost_sum[1] = min(cost[0], cost[1]);

			for (int i = 2; i < n; i++)
			{
				cost_sum[i] = min(cost_sum[i - 1] + cost[i], cost_sum[i - 2] + cost[i - 1]);
			}

			return cost_sum[n - 1];
		}

		static void test()
		{
			vector<int> cost1 = { 10, 15, 20 };
			vector<int> cost2 = { 1, 100, 1, 1, 1, 100, 1, 1, 100, 1 };

			int output1 = MinCostClimbingStairs(cost1);
			int output2 = MinCostClimbingStairs(cost2);

			OutputSingleNumber(output1);
			OutputSingleNumber(output2);
		}
	};
}

#endif // _MIN_COST_CLIMBING_STAIRS_H_
