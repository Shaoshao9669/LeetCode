#ifndef _CLIMBING_STAIRS_H_
#define _CLIMBING_STAIRS_H_

/*
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
*/

#include "common.h"

namespace ClimbingStairs
{
	class Solution
	{
	public:
		static int climbStairs(int n)
		{
			vector<int> sum(n);

			sum[0] = 1;
			sum[1] = 2;

			for (int i = 2; i < n; i++)
			{
				sum[i] = sum[i - 1] + sum[i - 2];
			}

			return sum[n - 1];
		}

		static void test()
		{
			int num1 = 2;
			int num2 = 4;

			int output1 = climbStairs(num1);
			int output2 = climbStairs(num2);

			OutputSingleNumber(output1);
			OutputSingleNumber(output2);
		}
	};
}


#endif // _CLIMBING_STAIRS_H_
