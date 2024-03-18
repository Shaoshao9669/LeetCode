#ifndef _SINGER_NUMBER_H_
#define _SINGER_NUMBER_H_

/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
You must implement a solution with a linear runtime complexity and use only constant extra space.

Example 1:
Input: nums = [2,2,1]
Output: 1

Example 2:
Input: nums = [4,1,2,1,2]
Output: 4

Example 3:
Input: nums = [1]
Output: 1
*/

#include "common.h"

namespace SingleNumber
{
	class Solution
	{
	public:
		static int singleNumber(vector<int>& nums)
		{
			int res = 0;

			for (int i = 0; i < (int)nums.size(); i++)
			{
				res = res ^ nums[i];
			}

			return res;
		}

		static void test()
		{
			vector<int> nums1 = { 2, 2, 1 };
			vector<int> nums2 = { 4, 1, 2, 1, 2 };
			vector<int> nums3 = { 1 };

			int num1 = singleNumber(nums1);
			int num2 = singleNumber(nums2);
			int num3 = singleNumber(nums3);

			OutputSingleNumber(num1);
			OutputSingleNumber(num2);
			OutputSingleNumber(num3);
		}
	};
}

#endif // _SINGER_NUMBER_H_
