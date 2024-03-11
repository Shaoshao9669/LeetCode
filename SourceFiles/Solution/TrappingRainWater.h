#ifndef _TRAPPING_RAIN_WATER_H_
#define _TRAPPING_RAIN_WATER_H_

/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

Example 2:
Input: height = [4,2,0,3,2,5]
Output: 9
*/

#include "common.h"

namespace TrappingRainWater
{
    class Solution 
    {
    public:
		static int findMax(int* array, int num)
		{
			int max = 0;

			for (int i = 0; i < num; i++)
			{
				if (max < array[i])
				{
					max = array[i];
				}
			}

			return max;
		}

		static int trap(vector<int>& height)
		{
			int sum = 0;
			int n = height.size();

			for (int i = 1; i < n - 1; i++)
			{
				int size = min(findMax(&height[0], i), findMax(&height[i + 1], n - i - 1)) - height[i];
				if (size < 0)
				{
					size = 0;
				}
				sum += size;
			}

			return sum;
        }

		static void test()
		{
			vector<int> height1 = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
			vector<int> height2 = { 4, 2, 0, 3, 2, 5 };

			int output1 = trap(height1);
			int output2 = trap(height2);

			OutputSingleNumber(output1);
			OutputSingleNumber(output2);
		}
    };
}

#endif // _TRAPPING_RAIN_WATER_H_
