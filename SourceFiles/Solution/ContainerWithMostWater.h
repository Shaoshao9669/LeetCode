#ifndef _CONTAINER_WITH_MOST_WATER_H_
#define _CONTAINER_WITH_MOST_WATER_H_

/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container.

Example 1:
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

Example 2:
Input: height = [1,1]
Output: 1
*/

#include "common.h"

namespace ContainerWithMostWater
{
	class Solution
	{
	public:
		static int maxArea(vector<int>& height)
		{
			int max_area = 0;

			for (int i = 0; i < (int)height.size(); i++)
			{
				for (int j = i; j < (int)height.size(); j++)
				{
					if ((min(height[i], height[j]) * (j - i) > max_area))
					{
						max_area = min(height[i], height[j]) * (j - i);
					}
				}
			}

			return max_area;
		}

		static void test()
		{
			vector<int> height1 = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
			vector<int> height2 = { 1, 1 };

			int output1 = maxArea(height1);
			int output2 = maxArea(height2);

			OutputSingleNumber(output1);
			OutputSingleNumber(output2);
		}
	};
}

#endif // _CONTAINER_WITH_MOST_WATER_H_
